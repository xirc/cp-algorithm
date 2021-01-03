#pragma once

#include <cmath>
#include <limits>
#include <queue>
#include <stdexcept>
#include <vector>

// Shortest Path Faster Algorithm
// More faster than Bellman-Ford on average.
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
class SPFA {
private:
    struct edge {
        size_t to;
        long long cost;
    };
    size_t N;
    std::vector<std::vector<edge>> edges;
    long long inf;

public:
    // Time: O(V)
    SPFA(
        size_t const N = 0,
        long long const inf = std::numeric_limits<long long>::max() / 2
    )
        : N(N)
        , edges(N)
        , inf(inf)
    {
        // Do nothing
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }
    // Time: O(1)
    long long infinity() const {
        return inf;
    }
    // from = [0,N), to = [0,N), cost = (-inf,inf)
    // O(1)
    void add_edge(size_t const from, size_t const to, long long const cost) {
        if (from >= N) throw std::out_of_range("from");
        if (to >= N) throw std::out_of_range("to");
        if (std::abs(cost) >= inf) throw std::out_of_range("cost");
        edges[from].push_back({ to, cost });
    }
    // from = [0,N)
    // O (E V)
    bool solve(size_t const from, std::vector<long long>& D, std::vector<size_t>& P) const {
        if (from >= N) throw std::out_of_range("from");

        D.assign(N, inf);
        P.assign(N, N);
        std::vector<size_t> count(N, 0);
        std::vector<bool> inqueue(N, false);
        std::queue<size_t> Q;

        D[from] = 0;
        Q.push(from);
        inqueue[from] = true;
        while (!Q.empty()) {
            size_t v = Q.front(); Q.pop();
            inqueue[v] = false;
            for (auto const& edge : edges[v]) {
                if (D[edge.to] <= D[v] + edge.cost) continue;
                D[edge.to] = D[v] + edge.cost;
                P[edge.to] = v;
                if (inqueue[edge.to]) continue;
                Q.push(edge.to);
                inqueue[edge.to] = true;
                count[edge.to]++;
                if (count[edge.to] > N) {
                    // Found a negative cycle
                    return false;
                }
            }
        }
        return true;
    }
};