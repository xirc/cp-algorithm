#pragma once

// Range Update and Point Query

#include <vector>

class BinaryIndexedTree {
    std::vector<int> bit;
    int m_size;

public:
    BinaryIndexedTree(int size)
        : m_size(size + 1)
        , bit(size + 1)
    {
        // Do nothing
    }

    int size() {
        return m_size - 1;
    }

    // Add value to array[l,r)
    // O(logN)
    void add(int l, int r, int value) {
        add(l, value);
        add(r, -value);
    }

    // Get value at array[index]
    // O(logN)
    int query(int index) {
        int ans = 0;
        for (++index; index > 0; index -= index & -index) {
            ans += bit[index];
        }
        return ans;
    }

private:
    void add(int index, int value) {
        if (index < 0) return;
        for (++index; index < m_size; index += index & -index) {
            bit[index] += value;
        }
    }
};