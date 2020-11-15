#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A

#include <vector>
#include <set>
#include <algorithm>
#include "../data-structure_union-find-tree/union-find-tree.hpp"

// Minimum Spanning Tree
// Kruskal's Algorithm
// Memory: O(V + E)
// NOTE: undirected, multi-edge, negative-weight
class Kruskal {
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
    Kruskal(int n = 0): N(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int index, int u, int v, int distance) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        edges.push_back({ index, u, v, distance });
    }
    // O (E logV)
    bool solve(long long& out_distance, std::vector<int>& out_edges) {
        out_distance = 0;
        out_edges.clear();

        UnionFindTree tree(N);

        std::sort(edges.begin(), edges.end());

        for (auto edge : edges) {
            if (tree.find(edge.u).leader == tree.find(edge.v).leader) continue;
            out_distance += edge.distance;
            out_edges.push_back(edge.index);
            tree.unite(edge.u, edge.v);
        }

        return out_edges.size() == N - 1;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};