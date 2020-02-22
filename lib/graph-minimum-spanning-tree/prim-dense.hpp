#pragma once

#include <vector>

class PrimDense {
    static const int inf = 1e8;
    int m_size;
    std::vector<std::vector<int>> adjmat;

public:
    PrimDense(int size)
        : m_size(size)
        , adjmat(size, std::vector<int>(size, inf)) {}

    int size() {
        return m_size;
    }

    void add_edge(int from, int to, int distance) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        adjmat[from][to] = distance;
        adjmat[to][from] = distance;
    }

    // O(V^2)
    bool solve(
        int& distance,
        std::vector<std::pair<int,int>>& edges
    ) {
        struct edge { int from, distance; };
        const int N = m_size;

        distance = 0;
        edges.clear();

        std::vector<bool> used(N, false);
        std::vector<edge> min_edge(N, { -1, inf });

        // Select vertex 0 at first.
        min_edge[0].distance = 0;

        for (int i = 0; i < N; ++i) {
            // Select destination vertex.
            int v = -1;
            for (int j = 0; j < N; ++j) {
                if (used[j]) continue;
                if (v == -1 || min_edge[j].distance < min_edge[v].distance) {
                    v = j;
                }
            }
            if (v == -1) {
                return false;
            }

            // Mark
            used[v] = true;
            distance += min_edge[v].distance;
            if (min_edge[v].from != -1) {
                edges.push_back({ min_edge[v].from, v });
            }

            // Update
            for (int to = 0; to < N; ++to) {
                if (adjmat[v][to] < min_edge[to].distance) {
                    min_edge[to] = { v, adjmat[v][to] };
                }
            }
        }

        return true;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index out of range";
    }
};