#pragma once

// Finding Sum in Two-Dimensional Array

#include <vector>

class BinaryIndexedTree {
    using T = long long;
    std::vector<std::vector<T>> bit;
    int size_n, size_m;

public:
    BinaryIndexedTree(int n, int m)
        : size_n(n + 1)
        , size_m(m + 1)
        , bit(n + 1, std::vector<T>(m + 1))
    {
        // Do nothing
    }

    std::pair<int,int> size() {
        return { size_n - 1, size_m - 1 };
    }

    // Sum of array[[0,x),[0,y)]
    // O(logN logN)
    T sum(int x, int y) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                ans += bit[i][j];
            }
        }
        return ans;
    }

    // Sum of array[[xl,xr),[yl,yr)]
    // O(logN logN)
    T sum(int xl, int xr, int yl, int yr) {
        T ans = 0;
        ans += sum(xr, yr);
        ans -= sum(xl, yr);
        ans -= sum(xr, yl);
        ans += sum(xl, yl);
        return ans;
    }

    // Add value at array[x,y]
    // O(logN logN)
    void add(int x, int y, T value) {
        for (int i = x + 1; i < size_n; i += i & -i) {
            for (int j = y + 1; j < size_m; j += j & -j) {
                bit[i][j] += value;
            }
        }
    }
};