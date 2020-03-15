// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450

#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <tuple>

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
    HeavyLightDecomposition(): HeavyLightDecomposition({}, {}) {}
    // O(N)
    HeavyLightDecomposition(
        const std::vector<std::vector<int>>& adj,
        const std::vector<int>& R = std::vector<int>({0})
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
    // O(N)
    void build(
        const std::vector<std::vector<int>>& adj,
        const std::vector<int>& R  = std::vector<int>({0})
    ) {
        int pos = 0;
        for (auto v : R) {
            dfs_prepare(adj, v);
            dfs_decompose(adj, v, pos);
        }
    }
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    int get_index(int v) {
        throw_if_invalid_index(v);
        return index[v];
    }
    // O(1)
    int get_vertex(int index) {
        throw_if_invalid_index(index);
        return inverse[index];
    }
    // O(1)
    int get_parent(int v) {
        throw_if_invalid_index(v);
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
#include <functional>

// SegmentTree (RangeUpdate,RangeQuery)
// Memory O(N)
// Build  O(N)
// Query O(log N)
// Update O(log N)
template<class T, class E>
class SegmentTree {
public:
    using value_type_T = T;
    using value_type_E = E;
    using F = std::function<T(const T&, const T&)>;
    using G = std::function<T(const T&, const E&)>;
    using H = std::function<E(const E&, const E&)>;

protected:
    F query_op;
    T query_id;
    G update_op;
    H lazy_op;
    E lazy_id;
    int N, M;
    std::vector<T> tree;
    std::vector<E> lazy;

public:
    // O(N)
    SegmentTree(
        int n,
        const F& query_op,
        const T& query_id,
        const G& update_op,
        const H& lazy_op,
        const E& lazy_id
    )
        : query_op(query_op)
        , query_id(query_id)
        , update_op(update_op)
        , lazy_op(lazy_op)
        , lazy_id(lazy_id)
    {
        build(std::vector<T>(n, query_id));
    }
    // O(N)
    template <class Query, class Update, class Lazy>
    SegmentTree(int n, Query query, Update update, Lazy lazy)
        : SegmentTree(
            n,
            std::bind(&Query::operator(), query, std::placeholders::_1, std::placeholders::_2),
            query.id,
            std::bind(&Update::operator(), update, std::placeholders::_1, std::placeholders::_2),
            std::bind(&Lazy::operator(), lazy, std::placeholders::_1, std::placeholders::_2),
            lazy.id
        )
    {
        // Do nothing
    }
    // O(1)
    int size() {
        return N;
    }
    // O(N log N)
    void dump(std::vector<T>& buffer) {
        buffer.clear();
        for (int i = 0; i < N; ++i) {
            buffer.push_back(query(i,i+1));
        }
    }
    // O(N)
    void build(const std::vector<T>& array) {
        N = array.size();
        M = N * 4;
        tree.assign(M, query_id);
        lazy.assign(M, lazy_id);
        build(array, 0, 0, N);
    }
    // O(log N)
    // [l,r)
    T query(int l, int r) {
        return query(0, 0, N, std::max(l,0), std::min(r,N));
    }
    // O(log N)
    // [l,r)
    void update(int l, int r, const E& value) {
        update(0, 0, N, l, r, value);
    }

protected:
    static constexpr int left(int v) { return v * 2 + 1; }
    static constexpr int right(int v) { return v * 2 + 2; }
    void build(const std::vector<T>& array, int v, int tl, int tr) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            tree[v] = array[tl];
        } else {
            const int tm = (tl + tr) / 2;
            build(array, left(v), tl, tm);
            build(array, right(v), tm, tr);
            tree[v] = query_op(tree[left(v)], tree[right(v)]);
        }
    }
    T query(int v, int tl, int tr, int l, int r) {
        if (l >= r) {
            return query_id;
        }
        update_lazy(v);
        if (l == tl && r == tr) {
            return tree[v];
        }
        const int tm = (tl + tr) / 2;
        const auto lhs = query(left(v), tl, tm, l, std::min(r,tm));
        const auto rhs = query(right(v), tm, tr, std::max(l,tm), r);
        return query_op(lhs, rhs);
    }
    void update(int v, int tl, int tr, int l, int r, const E& value) {
        if (l >= r) return;
        update_lazy(v);
        if (l == tl && r == tr) {
            lazy[v] = lazy_op(lazy[v], value);
            tree[v] = update_op(tree[v], value);
        } else {
            const int tm = (tl + tr) / 2;
            update(left(v), tl, tm, l, std::min(r, tm), value);
            update(right(v), tm, tr, std::max(l,tm), r, value);
            tree[v] = query_op(tree[left(v)], tree[right(v)]);
        }
    }
    void update_lazy(int v) {
        if (left(v) < M) {
            lazy[left(v)] = lazy_op(lazy[left(v)], lazy[v]);
            tree[left(v)] = update_op(tree[left(v)], lazy[v]);
        }
        if (right(v) < M) {
            lazy[right(v)] = lazy_op(lazy[right(v)], lazy[v]);
            tree[right(v)] = update_op(tree[right(v)], lazy[v]);
        }
        lazy[v] = lazy_id;
    }
};


#include <iostream>
#include <iomanip>
#include <algorithm>
#include <tuple>
using namespace std;

const long long inf = 1e18; 
struct Data {
    int count;
    long long sum, prefix, suffix, maximum;
    static Data make(int value) {
        return { 1, value, value, value, value };
    }
};
struct Option {
    bool active;
    int value;
    Option(): active(false), value(0) {}
    Option(int value): active(true), value(value) {}
};
struct Query {
    const Data id = { 0, 0, -inf, -inf, -inf };
    Data operator()(const Data& lhs, const Data& rhs) const {
        auto count = lhs.count + rhs.count;
        auto sum = lhs.sum + rhs.sum;
        auto prefix = max(lhs.sum + rhs.prefix, lhs.prefix);
        auto suffix = max(lhs.suffix + rhs.sum, rhs.suffix);
        auto maximum = max({ lhs.suffix + rhs.prefix, lhs.maximum, rhs.maximum });
        return { count, sum, prefix, suffix, maximum };
    }
};
struct Update {
    Data operator()(const Data& lhs, const Option& rhs) const {
        if (!rhs.active) {
            return lhs;
        }
        auto sum = rhs.value * lhs.count;
        auto prefix = max(rhs.value, sum);
        auto suffix = max(rhs.value, sum);
        auto maximum = max(rhs.value, sum);
        return {
            lhs.count, sum, prefix, suffix, maximum
        };
    }
};
struct Lazy {
    const Option id = Option();
    Option operator()(const Option& lhs, const Option& rhs) {
        if (rhs.active) {
            return rhs;
        }
        return lhs;
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
    SegmentTree<Data,Option> tree(N, Query(), Update(), Lazy());
    tree.build(vector<Data>(N, Data::make(0)));

    for (int i = 0; i < N; ++i) {
        int w = ws[hld.get_vertex(i)];
        tree.update(i, i+1, Option(w));
    }

    auto merge=[&](tuple<int,int,Data>& a, tuple<int,int,Data>& b, tuple<int,int,Data>& ans) {
        return hld.try_merge<Data>(
            a, b, ans,
            [&](Data& v) { swap(v.prefix,v.suffix); },
            [&](Data& a, Data& b) { return Query()(a,b); }
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
                tree.update(l, r, Option(c));
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