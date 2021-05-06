#pragma once

#include <queue>
#include <stdexcept>
#include <vector>


// Bipartite Check
//
// Memory: O(V + E)
//
// NOTE:
//  - undirected
//  - no-multi-edge
//  - self-loop
//
class BipartiteCheck {
    size_t N;
    std::vector<std::vector<size_t>> adj;

public:
    // Time: O(V)
    BipartiteCheck(size_t n = 0)
        : N(n)
        , adj(n)
    {
        // Do nothing
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }
    // u = [0,N), v = [0,N)
    // Time: O(1)
    void add_edge(size_t u, size_t v) {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Time: O(V)
    bool solve() const {
        bool is_bipartite = true;
        int const UNKNOWN = 2;
        std::vector<int> side(N, UNKNOWN);
        std::queue<size_t> Q;
        for (size_t i = 0; i < N; ++i) {
            if (side[i] != UNKNOWN) continue;
            Q.push(i);
            side[i] = 0;
            while (Q.size()) {
                auto v = Q.front(); Q.pop();
                for (auto u : adj[v]) {
                    if (side[u] == UNKNOWN) {
                        side[u] = side[v] ^ 1;
                        Q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
        return is_bipartite;
    }
};