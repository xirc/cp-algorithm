// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450

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

#include <vector>
#include <algorithm>

// SegmentTree (RangeUpdate,RangeQuery)
// Memory O(N)
// Build  O(N)
// Query O(log N)
// Update O(log N)
template<class T, class QueryMonoid, class UpdateMonoid, class Push>
class SegmentTree {
protected:
    int m_size;
    std::vector<T> m_tree;

public:
    SegmentTree(int n)
    {
        build(std::vector<T>(n,UpdateMonoid::id()));
    }
    // O(1)
    int size() {
        return m_size;
    }
    // O(N log N)
    void dump(std::vector<T>& buffer) {
        if (buffer.capacity() < m_size) {
            buffer.reserve(m_size);
        }
        buffer.clear();
        for (int i = 0; i < m_size; ++i) {
            buffer.push_back(query(i,i+1));
        }
    }
    // O(N)
    void build(const std::vector<T>& array) {
        m_size = array.size();
        m_tree.resize(m_size * 4);
        std::fill(m_tree.begin(), m_tree.end(), UpdateMonoid::id());
        build(array, 0, 0, m_size);
    }
    // O(log N)
    T query(int l, int r) {
        return query(0, 0, m_size, std::max(l,0), std::min(r,m_size));
    }
    // O(log N)
    void update(int l, int r, T value) {
        update(0, 0, m_size, l, r, value);
    }

protected:
    static constexpr int left(int v) {
        return v * 2 + 1;
    }
    static constexpr int right(int v) {
        return v * 2 + 2;
    }
    void build(const std::vector<T>& array, int v, int tl, int tr) {
        if (tr - tl <= 0) {
            return;
        }
        if (tr - tl == 1) {
            m_tree[v] = UpdateMonoid::op(m_tree[v], array[tl]);
        } else {
            const int tm = (tl + tr) / 2;
            build(array, left(v), tl, tm);
            build(array, right(v), tm, tr);
            m_tree[v] = QueryMonoid::op(m_tree[left(v)], m_tree[right(v)]);
        }
    }
    T query(int v, int tl, int tr, int l, int r) {
        if (l >= r) {
            return QueryMonoid::id();
        }
        if (l == tl && r == tr) {
            return m_tree[v];
        }
        Push::pushdown(m_tree[v], m_tree[left(v)], m_tree[right(v)]);
        const int tm = (tl + tr) / 2;
        const auto lhs = query(left(v), tl, tm, l, std::min(r,tm));
        const auto rhs = query(right(v), tm, tr, std::max(l,tm), r);
        return QueryMonoid::op(lhs, rhs);
    }
    void update(int v, int tl, int tr, int l, int r, T value) {
        if (l >= r) {
            return;
        }
        if (l == tl && r == tr) {
            m_tree[v] = UpdateMonoid::op(m_tree[v], value);
        } else {
            Push::pushdown(m_tree[v], m_tree[left(v)], m_tree[right(v)]);
            const int tm = (tl + tr) / 2;
            update(left(v), tl, tm, l, std::min(r, tm), value);
            update(right(v), tm, tr, std::max(l,tm), r, value);
            m_tree[v] = QueryMonoid::op(m_tree[left(v)], m_tree[right(v)]);
        }
    }
};

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <tuple>
using namespace std;

const long long inf = 1e18; 
struct Data {
    bool active;
    long long value, count;
    long long sum, prefix, suffix, maximum;
    static Data make(int value) {
        return { true, value, 0, value, value, value, value };
    }
};
struct Update {
    static Data id() {
        return Data { false, -inf, 1, 0, -inf, -inf, -inf };
    }
    static Data op(const Data& lhs, const Data& rhs) {
        auto sum = rhs.value * lhs.count;
        auto prefix = max(rhs.value, sum), suffix = max(rhs.value, sum);
        auto maximum = max(rhs.value, sum);
        return {
            true, rhs.value, lhs.count, sum, prefix, suffix, maximum
        };
    }
};
struct Query {
    static Data id() {
        return { false, -inf, 0, 0, -inf, -inf, -inf };
    }
    static Data op(const Data& lhs, const Data& rhs) {
        auto count = lhs.count + rhs.count;
        auto sum = lhs.sum + rhs.sum;
        auto prefix = max(lhs.sum + rhs.prefix, lhs.prefix);
        auto suffix = max(lhs.suffix + rhs.sum, rhs.suffix);
        auto maximum = max({ lhs.suffix + rhs.prefix, lhs.maximum, rhs.maximum });
        return Data { false, -inf, count, sum, prefix, suffix, maximum };
    }
};
struct Push {
    static void pushdown(Data& node, Data& left, Data& right) {
        if (!node.active) {
            return;
        }
        node.active = false;
        auto value = node.value;
        left.active = right.active = true;
        left.value = right.value = value;
        left.sum = value * left.count;
        left.prefix = left.suffix = left.maximum = max(value, left.sum);
        right.sum = value * right.count;
        right.prefix = right.suffix = right.maximum = max(value, right.sum);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    vector<int> ws;
    vector<vector<int>> adj;

    cin >> N >> Q;
    adj.assign(N, vector<int>());
    ws.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> ws[i];
    }
    for (int i = 0; i < N-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    HeavyLightDecomposition hld(adj, {0});
    SegmentTree<Data,Query,Update,Push> tree(N);
    for (int i = 0; i < N; ++i) {
        int w = ws[hld.get_vertex(i)];
        tree.update(i, i+1, Data::make(w));
    }

    auto merge=[&](tuple<int,int,Data>& a, tuple<int,int,Data>& b, tuple<int,int,Data>& ans) {
        return hld.try_merge<Data>(
            a, b, ans,
            [&](Data& v) { swap(v.prefix,v.suffix); },
            [&](Data& a, Data& b) { return Query::op(a,b); }
        );
    };
    auto merge_all=[&](vector<tuple<int,int,Data>>& a) {
        while (a.size() > 1) {
            auto x = a.back(); a.pop_back();
            for (int i = 0; i < a.size(); ++i) {
                tuple<int,int,Data> ans;
                if (merge(x,a[i],ans)) {
                    a[i] = ans;
                    break;
                }
            }
        }
        return a[0];
    };

    for (int i = 0; i < Q; ++i) {
        int t, a, b, c;
        cin >> t >> a >> b >> c;
        --a, --b;
        if (t == 1) {
            hld.for_each_vertex(a, b, [&](int l, int r) {
                tree.update(l, r, Data::make(c));
            });
        } else if (t == 2) {
            vector<tuple<int,int,Data>> qs;
            hld.for_each_vertex(a, b, [&](int l, int r) {
                auto x = tree.query(l, r);
                qs.push_back(make_tuple(l, r-1, x));
            });
            auto ans = merge_all(qs);
            cout << get<2>(ans).maximum << endl;
        } else throw;
    }

    return 0;
}