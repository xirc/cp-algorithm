#pragma once

// Finding Minimum of [0,r] in One-Dimensional Array

#include <algorithm>
#include <vector>
#include <climits>

class BinaryIndexedTree {
    std::vector<int> bit;
    int m_size;

public:
    BinaryIndexedTree(int size)
        : m_size(size+1)
        , bit(size+1, INT_MAX) {
    }

    int size() {
        return m_size - 1;
    }

    // Min of array[0..index)
    // O(logN)
    int min(int index) {
        if (index >= m_size) index = m_size - 1;
        int ans = INT_MAX;
        for (; index > 0; index -= index & -index) {
            ans = std::min(ans, bit[index]);
        }
        return ans;
    }

    // Update value at array[index].
    // The value should be smaller than array[index].
    // O(logN)
    void update(int index, int value) {
        if (index < 0 || index >= m_size) throw;
        for (++index; index < m_size; index += index & -index) {
            bit[index] = std::min(bit[index], value);
        }
    }
};