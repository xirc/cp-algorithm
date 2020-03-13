// https://onlinejudge.u-aizu.ac.jp/problems/0367

#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <tuple>

class HeavyLightDecomposition {
    int N;
    std::vector<int> index, inverse, out, head, heavy, parent, depth, subsize;

public:
    // O(N)
    HeavyLightDecomposition(
        const std::vector<std::vector<int>>& adj,
        std::vector<int> R = std::vector<int>({0})
    )
        : N(adj.size())
        , index(N,-1)
        , inverse(N,-1)
        , out(N,-1)
        , head(N,-1)
        , heavy(N,-1)
        , parent(N,-1)
        , depth(N,0)
        , subsize(N,0)
    {
        build(adj, R);
    }
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    int get_index(int v) {
        return index[v];
    }
    // O(1)
    int get_vertex(int index) {
        return inverse[index];
    }
    // O(1)
    int get_parent(int v) {
        return parent[v];
    }
    // O(1)
    // f [l,r)
    void for_each_subtree_vertex(int u, const std::function<void(int,int)>& f) {
        throw_if_invalid_index(u);
        f(index[u], out[u]);
    }
    // O(1)
    // f [l,r)
    void for_each_subtree_edge(int u, const std::function<void(int,int)>& f) {
        throw_if_invalid_index(u);
        f(index[u]+1, out[u]);
    }
    // O(logN)
    // f [l,r)
    void for_each_vertex(int u, int v, const std::function<void(int,int)>& f) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        for (; head[u] != head[v]; v = parent[head[v]]) {
            if (index[u] > index[v]) {
                std::swap(u, v);
            }
            f(index[head[v]], index[v]+1);
        }
        if (index[u] > index[v]) {
            std::swap(u, v);
        }
        f(index[u], index[v]+1);
    }
    // O(logN)
    // f [l,r)
    void for_each_edge(int u, int v, const std::function<void(int,int)>& f) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        for (; head[u] != head[v]; v = parent[head[v]]) {
            if (index[u] > index[v]) {
                std::swap(u, v);
            }
            f(index[head[v]], index[v]+1);
        }
        if (index[u] > index[v]) {
            std::swap(u, v);
        }
        f(index[u]+1, index[v]+1);
    }
    // O(logN)
    int lca(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        while (true) {
            if (index[u] > index[v]) {
                std::swap(u, v);
            }
            if (head[u] == head[v]) {
                return u;
            }
            v = parent[head[v]];
        }
    }
    // O(logN)
    int distance(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        return depth[u] + depth[v] - 2 * depth[lca(u,v)];
    }
    // O(1)
    // a: [l,r]+T
    // b: [l,r]+T
    template <class T>
    bool try_merge(
        const std::tuple<int,int,T>& a,
        const std::tuple<int,int,T>& b,
        std::tuple<int,int,T>& ans,
        const std::function<void(T&)> swap,
        const std::function<T(T&,T&)> merge
    ) {
        auto is_connect=[&](int u, int v) {
            return get_parent(u) == v || get_parent(v) == u;
        };
        auto al = std::get<0>(a), ar = std::get<1>(a); auto av = std::get<2>(a);
        auto bl = std::get<0>(b), br = std::get<1>(b); auto bv = std::get<2>(b);
        auto alv = get_vertex(al), arv = get_vertex(ar);
        auto blv = get_vertex(bl), brv = get_vertex(br);
        if (is_connect(alv,blv) || is_connect(alv,brv)) {
            std::swap(al,ar);
            std::swap(alv,arv);
            swap(av);
        }
        if (is_connect(arv,brv)) {
            std::swap(bl,br);
            std::swap(blv,brv);
            swap(bv);
        }
        if (is_connect(arv,blv)) {
            ans = std::make_tuple(al, br, merge(av,bv));
            return true;
        }
        return false;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    // O(N)
    void build(const std::vector<std::vector<int>>& adj, const std::vector<int>& R) {
        int pos = 0;
        for (auto v : R) {
            dfs_prepare(adj, v);
            dfs_decompose(adj, v, pos);
        }
    }
    // O(N)
    // NOTE: Don't use a recursive call for strict constraints.
    void dfs_prepare(const std::vector<std::vector<int>>& adj, int s) {
        std::stack<std::pair<int,int>> S;
        parent[s] = -1;
        depth[s] = 0;
        S.push({s,0});
        while (S.size()) {
            int v = S.top().first;
            int &i = S.top().second;
            if (i == -1) {
                i++;
                subsize[v] = 1;
            } else if (i < adj[v].size()) {
                int u = adj[v][i++];
                if (u == parent[v]) continue;
                parent[u] = v;
                depth[u] = depth[v] + 1;
                S.push({u, -1});
            } else {
                S.pop();
                int max_size = 0;
                for (auto u : adj[v]) {
                    if (parent[v] == u) continue;
                    subsize[v] += subsize[u];
                    if (subsize[u] > max_size) {
                        max_size = subsize[u];
                        heavy[v] = u;
                    }
                }
            }
        }
    }
    // O(N)
    // NOTE: Don't use a recursive call for strict constraints.
    void dfs_decompose(const std::vector<std::vector<int>>& adj, int s, int& pos) {
        std::stack<std::tuple<int,int,int>> S;
        S.push(std::make_tuple(s,s,-1));
        while (S.size()) {
            int v = std::get<0>(S.top());
            int h = std::get<1>(S.top());
            int &i = std::get<2>(S.top());
            if (i == -1) {
                i++;
                head[v] = h;
                index[v] = pos;
                inverse[pos] = v;
                pos++;
                if (heavy[v] != -1) {
                    S.push(std::make_tuple(heavy[v],h,-1));
                }
            } else if (i < adj[v].size()) {
                int u = adj[v][i++];
                if (parent[v] == u) continue;
                if (heavy[v] == u) continue;
                S.push(std::make_tuple(u,u,-1));
            } else {
                out[v] = pos;
                S.pop();
            }
        }
    }
};

#include <algorithm>
#include <vector>
#include <tuple>

// SegmentTree (PointUpdate,RangeQuery)
// Memory O(N)
// Build  O(N)
// Query O(log N)
// Update O(log N)
template<class T, class E>
class SegmentTree {
public:
    typedef std::function<T(const T&, const T&)> Query;
    typedef std::function<T(const T&, const E&)> Update;

protected:
    const Query query_op;
    const T query_id;
    const Update update_op;
    const E update_id;
    int m_size;
    std::vector<T> m_tree;

public:
    SegmentTree(int n, Query query_op, T query_id, Update update_op, E update_id)
        : query_op(query_op), query_id(query_id), update_op(update_op), update_id(update_id)
    {
        build(std::vector<E>(n, update_id));
    }

    // O(1)
    int size() {
        return m_size;
    }

    // O(N)
    void build(const std::vector<E>& array) {
        m_size = array.size();
        m_tree.resize(m_size * 4);
        std::fill(m_tree.begin(), m_tree.end(), query_id);
        build(array, 0, 0, m_size);
    }

    // find the value in range [l, r)
    // O(log N)
    T query(int l, int r) {
        return query(0, 0, m_size, std::max(l,0), std::min(r,m_size));
    }

    // update the value at index which is in range [0, n)
    // O(log N)
    bool update(int index, E value) {
        if (index < 0 || index >= m_size) {
            return false;
        }
        update(0, 0, m_size, index, value);
        return true;
    }

    // O(N logN)
    void dump(std::vector<T>& buffer) {
        if (buffer.capacity() < m_size) {
            buffer.reserve(m_size);
        }
        buffer.clear();
        for (int i = 0; i < m_size; ++i) {
            buffer.push_back(query(i,i+1));
        }
    }

protected:
    static constexpr int left(int v) { return v * 2 + 1; }
    static constexpr int right(int v) { return v * 2 + 2; }

    void build(const std::vector<E>& array, int v, int tl, int tr) {
        if (tr - tl <= 0) {
            return;
        }
        if (tr - tl == 1) {
            m_tree[v] = update_op(m_tree[v], array[tl]);
        } else {
            const int tm = (tl + tr) / 2;
            const int vl = left(v), vr = right(v);
            build(array, vl, tl, tm);
            build(array, vr, tm, tr);
            m_tree[v] = query_op(m_tree[vl], m_tree[vr]);
        }
    }

    T query(int v, int tl, int tr, int l, int r) {
        if (l >= r) {
            return query_id;
        }
        if (l == tl && r == tr) {
            return m_tree[v];
        }
        const int tm = (tl + tr) / 2;
        const int vl = left(v), vr = right(v);
        const auto lhs = query(vl, tl, tm, l, std::min(r,tm));
        const auto rhs = query(vr, tm, tr, std::max(l,tm), r);
        return query_op(lhs, rhs);
    }

    void update(int v, int tl, int tr, int index, E value) {
        if (tr - tl <= 0) {
            return;
        }
        if (tr - tl == 1) {
            m_tree[v] = update_op(m_tree[v], value);
        } else {
            const int tm = (tl + tr) / 2;
            const int vl = left(v), vr = right(v);
            if (index < tm) {
                update(vl, tl, tm, index, value);
            } else {
                update(vr, tm, tr, index, value);
            }
            m_tree[v] = query_op(m_tree[vl], m_tree[vr]);
        }
    }
};

#include <iostream>
#include <map>

using namespace std;

int N, K, Q;
vector<vector<int>> adj;
vector<long long> W;
vector<map<int,int>> C;

long long cost(int u, int v) {
    long long ans = W[u] + W[v] + C[u][v];
    return (ans % K) ? ans : 0;
}

struct Query {
    using T = tuple<int,int,long long>;
    static T id() {
        return make_tuple(-1,-1,-1);
    }
    static T op(const T& lhs, const T& rhs) {
        T l = lhs, r = rhs;
        if (l > r) swap(l,r);
        int ll, lr, rl, rr;
        long long lv, rv;
        tie(ll, lr, lv) = l;
        tie(rl, rr, rv) = r;
        if (ll < 0 || lr < 0) return r;
        if (C[ll].count(rl) || C[ll].count(rr)) swap(ll,lr);
        if (C[lr].count(rr)) swap(rl,rr);
        if (C[lr].count(rl)) {
            return T(ll,rr,lv+rv+cost(lr,rl));
        }
        return T(-1,-1,-1);
    }
};
struct Update {
    using E = long long;
    static E id() {
        return 0;
    }
    static Query::T op(const Query::T& lhs, const E& rhs) {
        return Query::T(rhs,rhs,0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    adj.assign(N, vector<int>());
    W.assign(N, 0);
    C.assign(N, map<int,int>());
    for (int i = 0; i < N - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        C[a][b] = C[b][a] = c;
    }

    HeavyLightDecomposition hld(adj, {0});

    SegmentTree<Query::T,Update::E> tree(N, Query::op, Query::id(), Update::op, Update::id());

    auto merge = [&](vector<tuple<int,int,Query::T>>& ans) {
        while (ans.size() > 1) {
            auto x = ans.back(); ans.pop_back();
            for (int i = 0; i < ans.size(); ++i) {
                tuple<int,int,Query::T> y;
                if (hld.try_merge<Query::T>(
                    x, ans[i], y,
                    [&](Query::T& v) { swap(get<0>(v), get<1>(v)); },
                    [&](const Query::T& lhs, const Query::T& rhs) { return Query::op(lhs,rhs); }
                )) {
                    ans[i] = y;
                    break;
                }
            }
        }
        return ans[0];
    };

    for (int i = 0 ; i < N; ++i) {
        tree.update(i, hld.get_vertex(i));
    }

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        string type;
        cin >> type;
        if (type == "add") {
            int x, d;
            cin >> x >> d;
            W[x] += d;
            tree.update(hld.get_index(x), x);
        } else if (type == "send") {
            int s, t;
            cin >> s >> t;
            vector<tuple<int,int,Query::T>> ans;
            hld.for_each_vertex(s, t, [&](int l, int r) {
                auto x = tree.query(l, r);
                ans.push_back(make_tuple(l,r-1,x));
            });
            cout << get<2>(get<2>(merge(ans))) << endl;
        } else throw;
    }

    return 0;
}