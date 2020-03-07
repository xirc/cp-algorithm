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
    int m_size;
    std::vector<node> m_nodes;

public:
    UnionFindTree(int size)
        : m_size(size)
        , m_nodes(size)
    {
        for (int i = 0; i < size; ++i) {
            m_nodes[i] = { i, 0, false, true };
        }
    }
    int size() {
        return m_size;
    }
    // O(a(n))
    node find_set(int index) {
        if (index < 0 || index >= m_size) throw;
        auto& node = m_nodes[index];
        if (index != node.parent) {
            // Path Compression
            auto root = find_set(node.parent);
            node.parent = root.parent;
            node.rank = root.rank;
            node.parity = root.parity ^ node.parity;
            node.bipartite = root.bipartite;
        }
        return node;
    }
    // O(a(n))
    void union_set(int a, int b) {
        auto ra = find_set(a);
        auto rb = find_set(b);

        a = ra.parent;
        b = rb.parent;

        if (a == b) {
            if (ra.parity == rb.parity) {
                m_nodes[a].bipartite = false;
            }
        } else {
            if (m_nodes[a].rank < m_nodes[b].rank) {
                std::swap(a, b);
                std::swap(ra, rb);
            }
            m_nodes[b].parent = a;
            m_nodes[b].parity = ra.parity ^ rb.parity ^ true;
            m_nodes[a].bipartite &= m_nodes[b].bipartite;
            if (m_nodes[a].rank == m_nodes[b].rank) {
                m_nodes[a].rank++;
            }
        }
    }
    // O(1)
    bool is_bipartite(int index) {
        return find_set(index).bipartite;
    }
};