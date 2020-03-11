#pragma once

#include <vector>
#include <cmath>
#include <algorithm>

// Monoid::op should be assosiative.
// op(op(x,y),z) = op(x,op(y,z))
template <class T, class Monoid>
class DisjointSparseTable {
    int N, L;
    std::vector<T> array;
    std::vector<std::vector<T>> table;
    std::vector<int> clz;

public:
    // O(N logN)
    DisjointSparseTable(const std::vector<T>& array)
    {
        this->array = array;
        int S = array.size();
        L = std::ceil(std::log2(std::max(S,2)));
        N = 1 << L;
        table.assign(L, std::vector<T>(N, Monoid::id()));
        build(0, 0, N);
    }
    // O(loglogN)
    // [l, r)
    T query(int l, int r) {
        l = std::max(l, 0);
        r = std::min(r, N);
        if (r - l <= 0) {
            return Monoid::id();
        }
        if (r - l == 1) {
            return array[l];
        }
        int k = msb(l^(r-1));
        int level = L - 1 - k;
        return Monoid::op(table[level][l], table[level][r-1]);
    }

private:
    // O(loglogN)
    int msb(int x) {
        int ans = 0;
        if (x >> 16) {
            x >>= 16; ans += 16;
        }
        if (x >> 8) {
            x >>= 8; ans += 8;
        }
        if (x >> 4) {
            x >>= 4; ans += 4;
        }
        if (x >> 2) {
            x >>= 2; ans += 2;
        }
        ans += x >> 1;
        return ans;
    }
    T value(int index) {
        if (index >= array.size()) {
            return Monoid::id();
        }
        return array[index];
    }
    // O(N logN), [l,r)
    void build(int level, int l, int r) {
        const int m = (l + r) / 2;

        table[level][m-1] = value(m-1);
        for (int i = m-2; i >= l; --i) {
            table[level][i] = Monoid::op(value(i), table[level][i+1]);
        }
        table[level][m] = value(m);
        for (int i = m+1; i < r; ++i) {
            table[level][i] = Monoid::op(table[level][i-1], value(i));
        }

        if (r - l >= 4) {
            build(level + 1, l, m);
            build(level + 1, m, r);
        }
    }
};