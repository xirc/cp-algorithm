#pragma once

#include <vector>
#include <algorithm>

struct Node {
    int parent;
    int rank;
    int length;
    Node()
        : parent(0)
        , rank(0)
        , length(0) {}
    Node(int parent, int rank, int length)
        : parent(parent)
        , rank(rank)
        , length(length) {}
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
            m_nodes[i] = Node(i, 0, 0);
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
            m_nodes[index].length += root.length;
        }
        return m_nodes[index];
    }
    // O(a(n))
    void union_set(int lindex, int rindex) {
        lindex = find_set(lindex).parent;
        rindex = find_set(rindex).parent;
        if (lindex == rindex) {
            return;
        }
        if (m_nodes[lindex].rank < m_nodes[rindex].rank) {
            std::swap(lindex, rindex);
        }
        // The distance between node 'lindex' and 'rindex' is 1.
        m_nodes[rindex].parent = lindex;
        m_nodes[rindex].length = 1;
        if (m_nodes[lindex].rank == m_nodes[rindex].rank) {
            m_nodes[lindex].rank++;
        }
    }
};