#pragma once

#include <vector>
#include <algorithm>

class FloydWarshall {
    const int inf = 1e8;
    int m_size;
    std::vector<std::vector<int>> m_adjmat;
public:
    FloydWarshall(int size)
        : m_size(size)
        , m_adjmat(size, std::vector<int>(size, inf)) {}
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index out of range";
    }
    int size() {
        return m_size;
    }
    void add_edge(int from, int to, int cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        m_adjmat[from][to] = std::min(cost, inf);
    }
    // O(V^3)
    void solve(std::vector<std::pair<int,int>>& cycle_pairs) {
        const int N = m_size;
        std::vector<std::vector<int>> D(N, std::vector<int>(N, inf));
        // Init
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    D[i][j] = 0;
                } else {
                    D[i][j] = m_adjmat[i][j];
                }
            }
        }
        // Floyd-Warshall
        for (int t = 0; t < N; ++t) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (D[i][t] >= inf || D[t][j] >= inf) continue;
                    D[i][j] = std::min(D[i][j], D[i][t] + D[t][j]);
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
};