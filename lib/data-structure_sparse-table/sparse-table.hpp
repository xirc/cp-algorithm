#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D

#include <vector>
#include <cmath>

template <class T, class Monoid>
class SparseTable {
    int N, K;
    std::vector<std::vector<T>> table;

public:
    // O(N logN)
    SparseTable(std::vector<T>& array) {
        build(array);
    }
    // [l,r)
    // O(logN)
    T query(int l, int r) {
        l = std::max(0, l);
        r = std::min(r, N);
        T ans = Monoid::id();
        for (int j = K - 1; j >= 0; --j) {
            int w = r - l;
            if ((1 << j) > w) continue;
            ans = Monoid::op(ans, table[l][j]);
            l += 1 << j;
        }
        return ans;
    }

private:
    // O(N)
    void build(std::vector<T>& array) {
        N = array.size();
        if (N == 0) return;
        K = std::ceil(std::log2(N)) + 1;
        table.assign(N, std::vector<int>(K, Monoid::id()));
        for (int i = 0; i < N; ++i) {
            table[i][0] = Monoid::op(array[i], Monoid::id());
        }
        for (int j = 1; j < K; ++j) {
            for (int i = 0; i < N; ++i) {
                int w = 1 << (j-1);
                if (i + w >= N) continue;
                table[i][j] = Monoid::op(table[i][j-1], table[i+w][j-1]);
            }
        }
    }
};