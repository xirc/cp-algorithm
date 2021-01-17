#pragma once

#include <cstdint>
#include <limits>
#include <queue>
#include <stdexcept>
#include <tuple>
#include <vector>


// Diameter of a Tree
//
// Space: O(V + E)
//
// NOTE:
//  - undirected edge
//  - non-loop
//  - non-multi-edge
//  - non-negative weight
//  - it can handle a forest
//
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A
//
class TreeDiameter {
private:
    struct edge {
        size_t to;
        uint64_t weight;
    };

    size_t N;
    std::vector<std::vector<edge>> adj;
    uint64_t inf;

public:
    // Time: O(V)
    TreeDiameter(
        size_t const N = 0,
        uint64_t const inf = std::numeric_limits<uint64_t>::max()
    )
      : N(N)
      , adj(N)
      , inf(inf)
    {
        // Do nothing
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }
    // u = [0,N), v = [0,N), w = [0,inf)
    // Time: O(1)
    void add_edge(size_t const u, size_t const v, uint64_t const w) {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("u");
        if (w >= inf) throw std::out_of_range("w");
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    // s = [0,N)
    // Time: O(E)
    std::tuple<size_t, size_t, uint64_t> solve(size_t s = 0) const {
        size_t u, v;
        uint64_t w;
        std::tie(u, w) = bfs(s);
        std::tie(v, w) = bfs(u);
        if (u > v) std::swap(u, v);
        return std::make_tuple(u, v, w);
    }

private:
    std::pair<size_t, uint64_t> bfs(size_t s) const {
        std::vector<uint64_t> D(N, inf);
        std::queue<size_t> Q;
        Q.push(s);
        D[s] = 0;
        while (Q.size()) {
            size_t u = Q.front(); Q.pop();
            for (auto const& e : adj[u]) {
                if (D[e.to] == inf) {
                    D[e.to] = D[u] + e.weight;
                    Q.push(e.to);
                }
            }
        }
        size_t v = N;
        for (size_t i = 0; i < N; ++i) {
            if (D[i] == inf) continue;
            if (v == N || D[i] > D[v]) {
                v = i;
            }
        }
        return std::make_pair(v, D[v]);
    }
};