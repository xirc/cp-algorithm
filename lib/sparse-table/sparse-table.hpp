#pragma once

#include <vector>
#include <cmath>

template <class T, class OP>
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
        T ans = OP::id();
        for (int j = K - 1; j >= 0; --j) {
            int w = r - l;
            if ((1 << j) > w) continue;
            ans = OP::op(ans, table[l][j]);
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
        table.assign(N, vector<int>(K, OP::id()));
        for (int i = 0; i < N; ++i) {
            table[i][0] = OP::op(array[i], OP::id());
        }
        for (int j = 1; j < K; ++j) {
            for (int i = 0; i < N; ++i) {
                int w = 1 << (j-1);
                if (i + w >= N) continue;
                table[i][j] = OP::op(table[i][j-1], table[i+w][j-1]);
            }
        }
    }
};