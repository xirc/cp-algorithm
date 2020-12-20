#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D

#include <vector>
#include <functional>
#include <cmath>

// SparseTable
// Memory: O(N logN)
// Query: O(logN)
template <class T>
class SparseTable {
public:
    using value_type_T = T;
    using F = std::function<T(const T&, const T&)>;

protected:
    int N, K;
    std::vector<std::vector<T>> table;
    F monoid_op;
    T monoid_id;

public:
    // O(N logN)
    SparseTable(
        const std::vector<T>& array,
        const F& monoid_op,
        const T& monoid_id
    )
        : monoid_op(monoid_op)
        , monoid_id(monoid_id)
    {
        build(array);
    }
    // O(N logN)
    template <class Monoid>
    SparseTable(const std::vector<T>& array, const Monoid& monoid)
        : SparseTable(
            array,
            std::bind(&Monoid::operator(), monoid, std::placeholders::_1, std::placeholders::_2),
            monoid.id
        )
    {
        // Do nothing
    }
    // [l,r)
    // O(logN)
    T query(int l, int r) {
        l = std::max(0, l);
        r = std::min(r, N);
        T ans = monoid_id;
        for (int j = K - 1; j >= 0; --j) {
            int w = r - l;
            if ((1 << j) > w) continue;
            ans = monoid_op(ans, table[l][j]);
            l += 1 << j;
        }
        return ans;
    }

protected:
    // O(N)
    void build(const std::vector<T>& array) {
        N = array.size();
        K = std::ceil(std::log2(std::max(N,1))) + 1;
        table.assign(N, std::vector<int>(K, monoid_id));
        for (int i = 0; i < N; ++i) {
            table[i][0] = monoid_op(array[i], monoid_id);
        }
        for (int j = 1; j < K; ++j) {
            for (int i = 0; i < N; ++i) {
                int w = 1 << (j-1);
                if (i + w >= N) continue;
                table[i][j] = monoid_op(table[i][j-1], table[i+w][j-1]);
            }
        }
    }
};