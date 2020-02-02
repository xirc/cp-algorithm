#pragma once

#include <vector>
#include <algorithm>

struct Node {
    int parent;
    int rank;
    bool parity;
    bool bipartite;
    Node()
        : parent(0)
        , rank(0)
        , parity(0)
        , bipartite(0) {}
    Node(int parent, int rank, bool parity, bool bipartite)
        : parent(parent)
        , rank(rank)
        , parity(parity)
        , bipartite(bipartite) {}
};

class UnionFindTree {
    int m_size;
    std::vector<Node> m_nodes;

public:
    UnionFindTree(int size)
        : m_size(size)
        , m_nodes(size)
    {
        for (int i = 0; i < size; ++i) {
            m_nodes[i] = Node(i, 0, false, true);
        }
    }
    int size() {
        return m_size;
    }
    // O(a(n))
    Node find_set(int index) {
        if (index < 0 || index >= m_size) throw;
        if (index != m_nodes[index].parent) {
            // Path Compression
            auto root = find_set(m_nodes[index].parent);
            m_nodes[index].parent = root.parent;
            m_nodes[index].parity = root.parity ^ m_nodes[index].parity;
            m_nodes[index].bipartite = root.bipartite;
        }
        return m_nodes[index];
    }
    // O(a(n))
    void union_set(int lindex, int rindex) {
        auto nl = find_set(lindex);
        auto nr = find_set(rindex);

        lindex = nl.parent;
        rindex = nr.parent;

        if (lindex == rindex) {
            if (nl.parity == nr.parity) {
                m_nodes[lindex].bipartite = false;
            }
        } else {
            if (m_nodes[lindex].rank < m_nodes[rindex].rank) {
                std::swap(lindex, rindex);
            }
            m_nodes[rindex].parent = lindex;
            m_nodes[rindex].parity = nl.parity ^ nr.parity ^ true;
            m_nodes[lindex].bipartite &= m_nodes[rindex].bipartite;
            if (m_nodes[lindex].rank == m_nodes[rindex].rank) {
                m_nodes[lindex].rank++;
            }
        }
    }
    // O(1)
    bool is_bipartite(int index) {
        return find_set(index).bipartite;
    }
};