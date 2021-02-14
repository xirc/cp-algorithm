// https://onlinejudge.u-aizu.ac.jp/problems/0367

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
vector<vector<size_t>> adj;
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
    adj.assign(N, vector<size_t>());
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
            auto ans = hld.reduce_each_vertex<Query::T>(s, t,
                [&](size_t l, size_t r, bool reverse) {
                    return tree.query(l, r);
                },
                [&](Query::T const& v) {
                    auto u = v;
                    swap(get<0>(u), get<1>(u));
                    return u;
                },
                [&](Query::T const& a, Query::T const& b) {
                    return Query::op(a, b);
                }
            );
            cout << get<2>(ans) << endl;
        } else throw;
    }

    return 0;
}