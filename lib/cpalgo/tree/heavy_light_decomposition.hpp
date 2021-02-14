#pragma once

#include <algorithm>
#include <cassert>
#include <functional>
#include <stack>
#include <stdexcept>
#include <tuple>
#include <vector>


// Heavy Light Decomposition
//
// Space: O(V + E)
//
// NOTE:
//  - undirected
//
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E
//  - https://onlinejudge.u-aizu.ac.jp/problems/0367
//  - https://onlinejudge.u-aizu.ac.jp/problems/2667
//  - https://onlinejudge.u-aizu.ac.jp/problems/2450
//
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