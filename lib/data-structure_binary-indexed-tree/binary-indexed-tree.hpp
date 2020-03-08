#pragma once

// Finding Sum in One-Dimensional Array

#include <vector>

class BinaryIndexedTree {
    using T = long long;
    std::vector<T> bit;
    int m_size;

public:
    BinaryIndexedTree(int size)
        : m_size(size+1)
        , bit(size+1) {
    }

    int size() {
        return m_size - 1;
    }

    // Sum of array[0..index)
    // O(logN)
    T sum(int index) {
        if (index >= m_size) index = m_size - 1;
        T ans = 0;
        for (; index > 0; index -= index & -index) {
            ans += bit[index];
        }
        return ans;
    }

    // Sum of array[l, r)
    // O(logN)
    T sum(int l, int r) {
        return sum(r) - sum(l);
    }

    // Add value to array[index]
    // O(logN)
    void add(int index, T value) {
        if (index < 0 || index >= m_size) throw;
        for (++index; index < m_size; index += index & -index) {
            bit[index] += value;
        }
    }
};