#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

class UnionFindTree {
public:
    struct node {
        int parent, rank, length;
    };

private:
    int m_size;
    std::vector<node> m_nodes;

public:
    UnionFindTree(int size)
        : m_size(size)
        , m_nodes(size)
    {
        for (int i = 0; i < size; ++i) {
            m_nodes[i] = { i, 0, 0 };
        }
    }
    int size() {
        return m_size;
    }
    // O(a(n))
    node find_set(int index) {
        if (index < 0 || index >= m_size) throw;
        if (index != m_nodes[index].parent) {
            // Path Compression
            auto root = find_set(m_nodes[index].parent);
            m_nodes[index].parent = root.parent;
            m_nodes[index].rank = root.rank;
            m_nodes[index].length += root.length;
        }
        return m_nodes[index];
    }
    // O(a(n))
    void union_set(int a, int b) {
        auto ra = find_set(a);
        auto rb = find_set(b);
        a = ra.parent;
        b = rb.parent;
        if (a == b) {
            return;
        }
        if (m_nodes[a].rank < m_nodes[b].rank) {
            std::swap(a, b);
            std::swap(ra, rb);
        }
        // The distance between node 'a' and 'b' is 1.
        m_nodes[b].parent = a;
        m_nodes[b].length = ra.length + 1;
        if (m_nodes[a].rank == m_nodes[b].rank) {
            m_nodes[a].rank++;
        }
    }
};