#pragma once

#include <vector>
#include <algorithm>

// Finding a negative cycle
// Memory: O(V^2 + E)
class FloydWarshall {
    static const long long inf = 1e18;
    int N;
    std::vector<std::vector<long long>> adjmat;

public:
    // O(V^2)
    FloydWarshall(int n = 0)
        : N(n)
        , adjmat(n, std::vector<long long>(n, inf))
    {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to, long long cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        adjmat[from][to] = std::min(cost, inf);
    }
    // O(V^3)
    void solve(std::vector<std::pair<int,int>>& cycle_pairs) {
        // Init
        auto D = adjmat;
        for (int i = 0; i < N; ++i) {
            D[i][i] = 0;
        }
        // Floyd-Warshall
        for (int t = 0; t < N; ++t) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (D[i][t] >= inf || D[t][j] >= inf) continue;
                    const auto distance = D[i][t] + D[t][j];
                    D[i][j] = std::min(D[i][j], std::max(-inf, distance));
                }
            }
        }
        // Cycle finding
        cycle_pairs.clear();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int t = 0; t < N; ++t) {
                    if (D[i][t] < inf && D[t][t] < 0 && D[t][j] < inf) {
                        D[i][j] = -inf;
                    }
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                if (D[i][j] < 0) {
                    cycle_pairs.push_back({i, j});
                }
            }
        }
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};