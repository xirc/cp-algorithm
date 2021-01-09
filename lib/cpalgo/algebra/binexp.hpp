#pragma once

#include <functional>


// Binary Exponentation
//
// Time: O(log(N))
// Space: O(1)
//
// See:
//  - https://cp-algorithms.com/algebra/euclid-algorithm.html
//
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
//
template<class T>
inline T binexp(
    T const& a,
    unsigned long long n,
    T const& id,
    std::function<T(T const& lhs, T const& rhs)> const& op = std::multiplies<T>()
)
{
    auto ans = id;
    auto p = a;
    while (n > 0) {
        if (n & 1) {
            ans = op(ans, p);
        }
        p = op(p, p);
        n >>= 1;
    }
    return ans;
}