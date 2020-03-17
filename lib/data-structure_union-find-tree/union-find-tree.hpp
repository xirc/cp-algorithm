#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A

#include <vector>
#include <algorithm>

// UnionFindTree
// Memory: O(N)
class UnionFindTree {
public:
    struct node { int parent, rank; };

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
            nodes[i] = { i, 0 };
        }
    }
    // O(1)
    int size() {
        return N;
    }
    // O(a(N))
    node find(int index) {
        throw_if_invalid_index(index);
        if (index != nodes[index].parent) {
            // Path Compression
            nodes[index] = find(nodes[index].parent);
        }
        return nodes[index];
    }
    // O(a(N))
    bool same(int a, int b) {
        throw_if_invalid_index(a);
        throw_if_invalid_index(b);
        return find(a).parent == find(b).parent;
    }
    // O(a(N))
    void unite(int a, int b) {
        throw_if_invalid_index(a);
        throw_if_invalid_index(b);
        a = find(a).parent;
        b = find(b).parent;
        if (a == b) {
            return;
        }
        if (nodes[a].rank < nodes[b].rank) {
            std::swap(a, b);
        }
        nodes[b].parent = a;
        if (nodes[a].rank == nodes[b].rank) {
            nodes[a].rank++;
        }
    }

protected:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};