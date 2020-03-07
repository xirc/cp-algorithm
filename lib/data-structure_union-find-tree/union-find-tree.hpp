#pragma once

#include <vector>
#include <algorithm>

class UnionFindTree {
    int m_size;
    std::vector<int> m_parents;
    std::vector<int> m_ranks;

public:
    UnionFindTree(int size)
        : m_size(size)
        , m_parents(size)
        , m_ranks(size)
    {
        for (int i = 0; i < size; ++i) {
            m_parents[i] = i;
        }
    }
    int size() {
        return m_size;
    }
    // O(a(N))
    int find_set(int index) {
        if (index < 0 || index >= m_size) throw;
        if (index == m_parents[index]) { // the node of 'index' is root one.
            return index;
        }
        // Path Compression
        return m_parents[index] = find_set(m_parents[index]);
    }
    // O(a(N))
    void union_set(int lindex, int rindex) {
        lindex = find_set(lindex);
        rindex = find_set(rindex);
        if (lindex == rindex) {
            return;
        }
        if (m_ranks[lindex] < m_ranks[rindex]) {
            std::swap(lindex, rindex);
        }
        m_parents[rindex] = lindex;
        if (m_ranks[lindex] == m_ranks[rindex]) {
            m_ranks[lindex]++;
        }
    }
};