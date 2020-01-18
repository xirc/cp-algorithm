#pragma once

#include <vector>

// SegmentTree
template<class T, class U>
class SegmentTreeBase {
protected:
    int m_size;
    std::vector<U> m_tree;

protected:
    virtual T at(int index) = 0;
    
public:
    SegmentTreeBase(int n)
        : m_size(n)
        , m_tree(n*4)
    {
        // Do nothing
    }

    // O(1)
    int size() {
        return m_size;
    }

    // O(N log N)
    void dump(std::vector<T>& buffer) {
        if (buffer.capacity() < m_size) {
            buffer.reserve(m_size);
        }
        buffer.clear();
        for (int i = 0; i < m_size; ++i) {
            buffer.push_back(at(i));
        }
    }

protected:
    static constexpr int left(int v) {
        return v * 2 + 1;
    }
    static constexpr int right(int v) {
        return v * 2 + 2;
    }
};