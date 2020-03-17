#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

class UnionFindTree {
public:
    struct node {
        int parent, rank, length;
    };

protected:
    int N;
    std::vector<node> nodes;

public:
    // O(N)
    UnionFindTree(int n)
        : N(n)
        , nodes(n)
    {
        for (int i = 0; i < N; ++i) {
            nodes[i] = { i, 0, 0 };
        }
    }
    // O(1)
    int size() {
        return N;
    }
    // O(a(n))
    node find(int index) {
        throw_if_invalid_index(index);
        if (index != nodes[index].parent) {
            // Path Compression
            auto root = find(nodes[index].parent);
            nodes[index].parent = root.parent;
            nodes[index].rank = root.rank;
            nodes[index].length += root.length;
        }
        return nodes[index];
    }
    // O(a(n))
    void unite(int a, int b) {
        throw_if_invalid_index(a);
        throw_if_invalid_index(b);
        auto ra = find(a);
        auto rb = find(b);
        a = ra.parent;
        b = rb.parent;
        if (a == b) {
            return;
        }
        if (nodes[a].rank < nodes[b].rank) {
            std::swap(a, b);
            std::swap(ra, rb);
        }
        // The distance between node 'a' and 'b' is 1.
        nodes[b].parent = a;
        nodes[b].length = ra.length + 1;
        if (nodes[a].rank == nodes[b].rank) {
            nodes[a].rank++;
        }
    }

protected:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};