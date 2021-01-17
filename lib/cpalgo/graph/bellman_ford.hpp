#pragma once

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>
#include <memory>
#include <stdexcept>
#include <vector>


// Bellman Ford Algorith
//
// Space: O(V + E)
//
// NOTE:
//  - directed
//  - multi-edge
//  - self-loop
//  - negative-weight
//
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
//
class BellmanFord {
private:
    struct edge {
        size_t from;
        size_t to;
        int64_t cost;
    };
    size_t N;
    std::vector<edge> edges;
    int64_t inf;

public:
    // Time: O(1)
    BellmanFord(
        size_t const N = 0,
        int64_t inf = std::numeric_limits<int64_t>::max() / 2
    )
        : N(N)
        , inf(inf)
    {
        // Do nothing
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }
    // Time: O(1)
    int64_t infinity() const {
        return inf;
    }
    // from = [0,N), to = [0,N), cost = (-inf,inf)
    // Time: O(1)
    void add_edge(size_t const from, size_t const to, int64_t const cost) {
        if (from >= N) throw std::out_of_range("from");
        if (to >= N) throw std::out_of_range("to");
        if (std::abs(cost) >= inf) std::out_of_range("cost");
        edges.push_back({ from, to, cost });
    }
    // from = [0,N)
    // time: O (EV)
    bool solve(size_t const from, std::vector<int64_t>& D, std::vector<size_t>& P) const {
        if (from >= N) throw std::out_of_range("from");

        D.assign(N, inf);
        P.assign(N, N);

        bool any_update = false;
        D[from] = 0;
        for (size_t i = 0; i < N; ++i) {
            any_update = false;
            for (auto const& e : edges) {
                if (D[e.from] >= inf) continue;
                if (D[e.to] > D[e.from] + e.cost) {
                    // suppress negative overflow
                    D[e.to] = std::max(-inf, D[e.from] + e.cost);
                    P[e.to] = e.from;
                    any_update = true;
                }
            }
            if (!any_update) break;
        }

        // if any_update == true, a negative cycle is found.
        return !any_update;
    }
};