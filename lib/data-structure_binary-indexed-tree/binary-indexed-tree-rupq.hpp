#pragma once

// Range Update and Point Query

#include <vector>

class BinaryIndexedTree {
    using T = long long;
    std::vector<T> bit;
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
    void add(int l, int r, T value) {
        add(l, value);
        add(r, -value);
    }

    // Get value at array[index]
    // O(logN)
    T query(int index) {
        T ans = 0;
        for (++index; index > 0; index -= index & -index) {
            ans += bit[index];
        }
        return ans;
    }

private:
    void add(int index, T value) {
        if (index < 0) return;
        for (++index; index < m_size; index += index & -index) {
            bit[index] += value;
        }
    }
};