// https://onlinejudge.u-aizu.ac.jp/problems/2667

#include <bits/stdc++.h>

class HeavyLightDecomposition {
    size_t N;
    std::vector<size_t> index, inverse, out, head, heavy, parent, depth, subsize;

public:
    // Time: O(N)
    HeavyLightDecomposition(
        std::vector<std::vector<size_t>> const& adj = {},
        std::vector<size_t> const& R = {}
    )
    {
        build(adj, R);
    }
    // Time: O(N)
    void build(
        std::vector<std::vector<size_t>> const& adj,
        std::vector<size_t> const& R  = { }
    ) {
        N = adj.size();
        index.assign(N, N);
        inverse.assign(N, N);
        out.assign(N, N);
        head.assign(N, N);
        heavy.assign(N, N);
        parent.assign(N, N);
        depth.assign(N, 0);
        subsize.assign(N, 0);

        size_t pos = 0;
        for (auto v : R) {
            dfs_prepare(adj, v);
            dfs_decompose(adj, v, pos);
        }
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }
    // v = [0,N)
    // Time: O(1)
    size_t get_index(size_t v) const {
        if (v >= N) throw std::out_of_range("v");
        return index[v];
    }
    // index = [0,N)
    // Time: O(1)
    size_t get_vertex(size_t index) const {
        if (index >= N) throw std::out_of_range("index");
        return inverse[index];
    }
    // v = [0,N)
    // Time: O(1)
    size_t get_parent(size_t v) const {
        if (v >= N) throw std::out_of_range("v");
        return parent[v];
    }
    // u = [0,N), v = [0,N)
    // Time: O(logN)
    size_t lca(size_t u, size_t v) const {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");
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
    // u = [0,N), v = [0,N)
    // Time: O(logN)
    size_t distance(size_t u, size_t v) const {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");
        return depth[u] + depth[v] - 2 * depth[lca(u,v)];
    }
    // u = [0,N)
    // Time: O(1)
    void for_subtree_vertex(
        size_t u,
        std::function<void(size_t l, size_t r)> const& f
    ) const {
        if (u >= N) throw std::out_of_range("u");
        f(index[u], out[u]);
    }
    // u = [0,N)
    // Time: O(1)
    void for_subtree_edge(
        size_t u,
        std::function<void(size_t l, size_t r)> const& f
    ) const {
        if (u >= N) throw std::out_of_range("u");
        f(index[u]+1, out[u]);
    }
    // u = [0,N), v = [0,N)
    // Time: O(logN)
    void for_each_vertex(
        size_t u,
        size_t v,
        std::function<void(size_t l, size_t r, bool reverse)> const& f
    ) const {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");
        bool reverse = false;
        for (; head[u] != head[v]; v = parent[head[v]]) {
            if (index[u] > index[v]) {
                std::swap(u, v);
                reverse ^= true;
            }
            f(index[head[v]], index[v]+1, reverse);
        }
        if (index[u] > index[v]) {
            std::swap(u, v);
            reverse ^= true;
        }
        f(index[u], index[v]+1, reverse);
    }
    // u = [0,N), v = [0,N)
    // f [l,r)
    // Time: O(logN)
    void for_each_edge(
        size_t u,
        size_t v,
        std::function<void(size_t l, size_t r, bool reverse)> const& f
    ) const {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");
        bool reverse = false;
        for (; head[u] != head[v]; v = parent[head[v]]) {
            if (index[u] > index[v]) {
                std::swap(u, v);
                reverse ^= true;
            }
            f(index[head[v]], index[v]+1, reverse);
        }
        if (index[u] > index[v]) {
            std::swap(u, v);
            reverse ^= true;
        }
        f(index[u]+1, index[v]+1, reverse);
    }
    // u = [0,N), v = [0,N)
    // Time: O(logN logN)
    template <class T>
    T reduce_each_vertex(
        size_t u,
        size_t v,
        std::function<T(size_t l, size_t r, bool reverse)> const& value,
        std::function<T(T const& v)> const& inverse,
        std::function<T(T const& av, T const& bv)> const& merge
    ) const {
        return reduce_each_vertex<T>(u, v, value, inverse, [&](T const& av, T const& bv, size_t a, size_t b) {
            return merge(av, bv);
        });
    }
    // u = [0,N), v = [0,N)
    // Time: O(logN logN)
    template <class T>
    T reduce_each_vertex(
        size_t u,
        size_t v,
        std::function<T(size_t l, size_t r, bool reverse)> const& value,
        std::function<T(T const& v)> const& inverse,
        std::function<T(T const& av, T const& bv, size_t a, size_t b)> const& merge
    ) const {
        std::vector<std::tuple<size_t,size_t,T>> ts;
        for_each_vertex(u, v, [&](auto l, auto r, bool reverse) {
            auto lv = get_vertex(l), rv = get_vertex(r-1);
            ts.push_back(std::make_tuple(lv, rv, value(l, r, reverse)));
        });
        auto try_merge = [&](
            std::tuple<size_t,size_t,T> const& a,
            std::tuple<size_t,size_t,T> const& b,
            std::tuple<size_t,size_t,T>& ans
        ) {
            auto is_connected = [&](size_t u, size_t v) {
                return get_parent(u) == v || get_parent(v) == u;
            };
            auto alv = std::get<0>(a), arv = std::get<1>(a); auto av = std::get<2>(a);
            auto blv = std::get<0>(b), brv = std::get<1>(b); auto bv = std::get<2>(b);
            if (is_connected(alv,blv) || is_connected(alv, brv)) {
                std::swap(alv, arv);
                av = inverse(av);
            }
            if (is_connected(arv,brv)) {
                std::swap(blv, brv);
                bv = inverse(bv);
            }
            // arv and blv may be connected
            if (is_connected(arv,blv)) {
                auto v = merge(av, bv, arv, blv);
                ans = std::make_tuple(alv, brv, v);
                return true;
            }
            return false;
        };
        while (ts.size() > 1) {
            auto x = ts.back(); ts.pop_back();
            bool found = false;
            for (size_t i = 0; i < ts.size(); ++i) {
                std::tuple<size_t,size_t,T> y;
                if (try_merge(x, ts[i], y)) {
                    ts[i] = y;
                    found = true;
                    break;
                }
            }
            assert(found);
        }
        return std::get<2>(ts[0]);
    }
    // u = [0,N), v = [0,N)
    // Time: O(logN logN)
    template <class T>
    T reduce_each_edge(
        size_t u,
        size_t v,
        std::function<T(size_t l, size_t r, bool reverse)> const& value,
        std::function<T(T const& v)> const& inverse,
        std::function<T(T const& av, T const& bv)> const& merge
    ) const {
        return reduce_each_edge<T>(u, v, value, inverse, [&](T const& av, T const& bv, size_t a, size_t b) {
            return merge(av, bv);
        });
    }
    // u = [0,N), v = [0,N)
    // Time: O(logN logN)
    template <class T>
    T reduce_each_edge(
        size_t u,
        size_t v,
        std::function<T(size_t l, size_t r, bool reverse)> const& value,
        std::function<T(T const& v)> const& inverse,
        std::function<T(T const& av, T const& bv, size_t a, size_t b)> const& merge
    ) const {
        std::vector<std::tuple<size_t,size_t,T>> ts;
        for_each_edge(u, v, [&](auto l, auto r, bool reverse) {
            auto lv = get_vertex(l), rv = get_vertex(r-1);
            ts.push_back(std::make_tuple(lv, rv, value(l, r, reverse)));
        });
        auto try_merge = [&](
            std::tuple<size_t,size_t,T> const& a,
            std::tuple<size_t,size_t,T> const& b,
            std::tuple<size_t,size_t,T>& ans
        ) {
            auto is_connected = [&](size_t u, size_t v) {
                // The function is different from than vertex version.
                // In edge version, nodes can be connected if they have the same parent.
                return get_parent(u) == v || get_parent(v) == u || get_parent(u) == get_parent(v);
            };
            auto alv = std::get<0>(a), arv = std::get<1>(a); auto av = std::get<2>(a);
            auto blv = std::get<0>(b), brv = std::get<1>(b); auto bv = std::get<2>(b);
            if (is_connected(alv,blv) || is_connected(alv, brv)) {
                std::swap(alv, arv);
                av = inverse(av);
            }
            if (is_connected(arv,brv)) {
                std::swap(blv, brv);
                bv = inverse(bv);
            }
            // arv and blv may be connected
            if (is_connected(arv, blv)) {
                auto v = merge(av, bv, arv, blv);
                ans = std::make_tuple(alv, brv, v);
                return true;
            }
            return false;
        };
        while (ts.size() > 1) {
            auto x = ts.back(); ts.pop_back();
            bool found = false;
            for (size_t i = 0; i < ts.size(); ++i) {
                std::tuple<size_t,size_t,T> y;
                if (try_merge(x, ts[i], y)) {
                    ts[i] = y;
                    found = true;
                    break;
                }
            }
            assert(found);
        }
        return std::get<2>(ts[0]);
    }

private:
    // Time: O(N)
    // NOTE: Don't use a recursive call for strict constraints.
    void dfs_prepare(std::vector<std::vector<size_t>> const& adj, size_t s) {
        std::stack<std::pair<size_t,int>> S;
        parent[s] = N;
        depth[s] = 0;
        S.push({ s, -1 });
        while (S.size()) {
            auto v = S.top().first;
            auto &i = S.top().second;
            if (i == -1) {
                i++;
                subsize[v] = 1;
            } else if ((uint64_t)i < adj[v].size()) {
                auto u = adj[v][i++];
                if (u == parent[v]) continue;
                parent[u] = v;
                depth[u] = depth[v] + 1;
                S.push({ u, -1 });
            } else {
                S.pop();
                size_t max_size = 0;
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
    // Time: O(N)
    // NOTE: Don't use a recursive call for strict constraints.
    void dfs_decompose(std::vector<std::vector<size_t>> const& adj, size_t s, size_t& pos) {
        std::stack<std::tuple<size_t,size_t,int>> S;
        S.push(std::make_tuple(s, s, -1));
        while (S.size()) {
            size_t v = std::get<0>(S.top());
            size_t h = std::get<1>(S.top());
            int &i = std::get<2>(S.top());
            if (i == -1) {
                i++;
                head[v] = h;
                index[v] = pos;
                inverse[pos] = v;
                pos++;
                if (heavy[v] != N) {
                    S.push(std::make_tuple(heavy[v], h, -1));
                }
            } else if ((uint64_t)i < adj[v].size()) {
                auto u = adj[v][i++];
                if (parent[v] == u) continue;
                if (heavy[v] == u) continue;
                S.push(std::make_tuple(u, u, -1));
            } else {
                out[v] = pos;
                S.pop();
            }
        }
    }
};

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


using namespace std;

struct Data {
    long long value;
    int count;
    Data(): value(0), count(0) {}
    Data(long long value): value(value), count(1) {}
};
struct Query {
    const Data id = Data();
    Data operator()(const Data& lhs, const Data& rhs) const {
        Data ans;
        ans.count = lhs.count + rhs.count;
        ans.value = lhs.value + rhs.value;
        return ans;
    }
};
struct Update {
    Data operator()(const Data& lhs, const int& rhs) const {
        Data ans;
        ans.count = lhs.count;
        ans.value = lhs.value + rhs * lhs.count;
        return ans;
    }
};
struct Lazy {
    const int id = 0;
    int operator()(const int& lhs, const int& rhs) const {
        return lhs + rhs;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    vector<vector<size_t>> adj;

    cin >> N >> Q;
    adj.assign(N, vector<size_t>());
    for (int i = 0; i < N-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    HeavyLightDecomposition hld(adj, {0});
    SegmentTree<Data,int> tree(N, Query(), Update(), Lazy());
    tree.build(vector<Data>(N, Data(0)));

    for (int i = 0; i < Q; ++i) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            long long ans = 0;
            hld.for_each_edge(x, y, [&](size_t l, size_t r, bool reverse) {
                ans += tree.query(l, r).value;
            });
            cout << ans << endl;
        } else if (c == 1) {
            hld.for_subtree_edge(x, [&](size_t l, size_t r) {
                tree.update(l, r, y);
            });
        } else throw;
    }

    return 0;
}