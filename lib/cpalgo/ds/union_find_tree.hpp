#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>


// Union Find Tree
// (aka Disjoint Set Union)
//
// Space: O(N)
//
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A
//
class UnionFindTree {
public:
    struct node {
        size_t leader;
        size_t rank;
    };

private:
    size_t N;
    std::vector<node> nodes;

public:
    // Time: O(N)
    UnionFindTree(size_t const N = 0)
        : N(N)
        , nodes(N)
    {
        for (size_t i = 0; i < N; ++i) {
            nodes[i] = { i, 0 };
        }
    }
    // Time: O(1)
    size_t size() {
        return N;
    }
    // v = [0,N)
    // Time: O(a(N))
    node find(size_t const v) {
        throw_if_invalid_index(v);
        if (v != nodes[v].leader) {
            // Path Compression
            nodes[v] = find(nodes[v].leader);
        }
        return nodes[v];
    }
    // u = [0,N), v = [0,N)
    // Time: O(a(N))
    bool same(size_t const u, size_t const v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        return find(u).leader == find(v).leader;
    }
    // u = [0,N), v = [0,N)
    // Time: O(a(N))
    bool unite(size_t u, size_t v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        u = find(u).leader;
        v = find(v).leader;
        if (u == v) {
            return false;
        }
        if (nodes[u].rank < nodes[v].rank) {
            std::swap(u, v);
        }
        nodes[v].leader = u;
        if (nodes[u].rank == nodes[v].rank) {
            nodes[u].rank++;
        }
        return true;
    }

private:
    void throw_if_invalid_index(size_t const v) {
        if (v >= N) throw std::out_of_range("index out of range");
    }
};