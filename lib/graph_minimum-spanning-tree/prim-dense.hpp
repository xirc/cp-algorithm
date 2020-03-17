#pragma once

#include <vector>

class PrimDense {
    static const long long inf = 1e18;
    int N;
    std::vector<std::vector<long long>> adjmat;

public:
    // O(V^2)
    PrimDense(int size)
        : N(size)
        , adjmat(size, std::vector<long long>(size, inf))
    {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to, long long distance) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        adjmat[from][to] = distance;
        adjmat[to][from] = distance;
    }
    // O(V^2)
    bool solve(
        long long& distance,
        std::vector<std::pair<int,int>>& edges
    ) {
        struct edge { int from; long long distance; };

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
        if (index < 0 || index >= N) throw "index out of range";
    }
};