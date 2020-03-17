#pragma once

#include <vector>
#include <algorithm>

class UnionFindTree {
public:
    struct node {
        int parent, rank;
        bool parity, bipartite;
    };

private:
    int N;
    std::vector<node> nodes;

public:
    // O(N)
    UnionFindTree(int n)
        : N(n)
        , nodes(n)
    {
        for (int i = 0; i < N; ++i) {
            nodes[i] = { i, 0, false, true };
        }
    }
    // O(1)
    int size() {
        return N;
    }
    // O(a(n))
    node find(int index) {
        throw_if_invalid_index(index);
        auto& node = nodes[index];
        if (index != node.parent) {
            // Path Compression
            auto root = find(node.parent);
            node.parent = root.parent;
            node.rank = root.rank;
            node.parity = root.parity ^ node.parity;
            node.bipartite = root.bipartite;
        }
        return node;
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
            if (ra.parity == rb.parity) {
                nodes[a].bipartite = false;
            }
        } else {
            if (nodes[a].rank < nodes[b].rank) {
                std::swap(a, b);
                std::swap(ra, rb);
            }
            nodes[b].parent = a;
            nodes[b].parity = ra.parity ^ rb.parity ^ true;
            nodes[a].bipartite &= nodes[b].bipartite;
            if (nodes[a].rank == nodes[b].rank) {
                nodes[a].rank++;
            }
        }
    }
    // O(1)
    bool is_bipartite(int index) {
        throw_if_invalid_index(index);
        return find(index).bipartite;
    }

protected:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};