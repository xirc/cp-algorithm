#pragma once

// Range Updates and Range Queries

#include <vector>

class BinaryIndexedTree {
    std::vector<int> bit1;
    std::vector<int> bit2;
    int m_size;

public:
    BinaryIndexedTree(int size)
        : m_size(size + 1)
        , bit1(size + 1)
        , bit2(size + 1)
    {
        // Do nothing
    }

    int size() {
        return m_size - 1;
    }

    void add(int l, int r, int value) {
        add(bit1, l, value);
        add(bit1, r, -value);
        add(bit2, l, value * (l-1));
        add(bit2, r, -value * (r-1));
    }

    int sum(int index) {
        return sum(bit1, index) * (index - 1) - sum(bit2, index);
    }

    int sum(int l, int r) {
        return sum(r) - sum(l);
    }

private:
    void add(std::vector<int>& bit, int index, int value) {
        for (index++; index < m_size; index += index & -index) {
            bit[index] += value;
        }
    }
    int sum(std::vector<int>& bit, int index) {
        int ans = 0;
        for (; index > 0; index -= index & -index) {
            ans += bit[index];
        }
        return ans;
    }

};