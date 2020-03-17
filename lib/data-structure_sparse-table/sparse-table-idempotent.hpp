#pragma once

#include <vector>
#include <functional>
#include <cmath>

// SparseTable
// Memory: O(N logN)
// Query: O(1)
// NOTE: monoid.operator() should be idempotent function op(x,x) = x.
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
    // O(1)
    // [l,r)
    T query(int l, int r) {
        l = std::max(0, l);
        r = std::min(r, N);
        int w = r - l;
        if (w <= 0) return monoid_id;
        int j = std::floor(std::log2(w));
        return monoid_op(table[l][j], table[r - (1 << j)][j]);
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