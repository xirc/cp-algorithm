#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A

#include <vector>
#include <set>
#include <algorithm>

// Minimum Spanning Tree
// Kruskal's Algorithm
// Memory: O(V + E)
// NOTE: undirected, multi-edge, negative-weight
class KruskalSimple {
    struct edge {
        int index;
        int u, v;
        long long distance;
        bool operator<(const edge& other) const {
            return distance < other.distance;
        }
    };

    int N;
    std::vector<edge> edges;

public:
    // O(1)
    KruskalSimple(int n = 0): N(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int index, int u, int v, long long distance) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        edges.push_back({ index, u, v, distance });
    }
    // O(E logV + V^2)
    bool solve(long long& out_distance, std::vector<int> &out_edges) {
        out_distance = 0;
        out_edges.clear();

        std::vector<int> tree_id(N);
        
        for (int i = 0; i < N; ++i) {
            tree_id[i] = i;
        }
        std::sort(edges.begin(), edges.end());

        for (auto edge : edges) {
            if (tree_id[edge.u] == tree_id[edge.v]) continue;

            out_distance += edge.distance;
            out_edges.push_back(edge.index);

            int old_id = tree_id[edge.u], new_id = tree_id[edge.v];
            for (int i = 0; i< N; ++i) {
                if (tree_id[i] == old_id) {
                    tree_id[i] = new_id;
                }
            }
        }

        return out_edges.size() == N - 1;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};