#pragma once

#include <vector>

// Minimum Spanning Tree
// Prim's Algorithm for Dense Graph
// Memory: O(V^2)
// NOTE: undirected, no-multi-edge, negative-weight
class PrimDense {
    int N;
    std::vector<std::vector<long long>> adjmat;

public:
    static const long long inf;
    // O(V^2)
    PrimDense(int n = 0)
        : N(n)
        , adjmat(n, std::vector<long long>(n, inf))
    {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int u, int v, long long distance) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        adjmat[u][v] = distance;
        adjmat[v][u] = distance;
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
const long long PrimDense::inf = 1e18;