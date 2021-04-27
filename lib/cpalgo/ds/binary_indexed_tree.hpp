#pragma once

#include <functional>
#include <stdexcept>
#include <vector>

// Binary Indexed Tree
//
// Space: O(N)
// Time:
//   Query: O(logN)
//   Update: O(logN)
//
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
//
template <class T = int64_t>
class BinaryIndexedTree {
public:
    using F = std::function<T(T const&, T const&)>;

protected:
    size_t N;
    std::vector<T> bit;
    T empty;
    F combine_func;
    F remove_func;

public:
    // Time: O(N)
    BinaryIndexedTree(
        size_t n = 0,
        T empty = T(),
        F combine = std::plus<T>(),
        F remove = std::minus<T>()
    )
        : N(n+1)
        , bit(n+1, empty)
        , empty(empty)
        , combine_func(combine)
        , remove_func(remove)
    {
        // Do nothing
    }
    // Time: O(1)
    size_t size() const {
        return N - 1;
    }
    // Fold elements of array[0..index)
    // index = [0,N]
    // Time: O(logN)
    T fold(size_t index) const {
        if (index > N) throw std::out_of_range("index");
        T ans = empty;
        for (; index > 0; index -= index & -index) {
            ans = combine_func(ans, bit[index]);
        }
        return ans;
    }
    // Fold elements of array[l, r)
    // l = [0,N]
    // r = [l,N]
    // Time: O(logN)
    T fold(size_t l, size_t r) const {
        if (l > N) throw std::out_of_range("l");
        if (r < l || r > N) throw std::out_of_range("r");
        return remove_func(fold(r), fold(l));
    }
    // Combine given value to array[index]
    // index = [0,N)
    // Time: O(logN)
    void combine(size_t index, T const& value) {
        if (index >= N) throw std::out_of_range("index");
        for (++index; index < N; index += index & -index) {
            bit[index] = combine_func(bit[index], value);
        }
    }
};
