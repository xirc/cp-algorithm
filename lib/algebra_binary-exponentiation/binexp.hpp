#pragma once

#include <functional>

// Binary Exponentation
// Time: O(logN)
// Memory: O(1)
template<class T>
T binexp(
    const T& a,
    long long n,
    const T& id,
    const std::function<T(const T&, const T&)> op = std::multiplies<T>()
) {
    if (n < 0) throw;

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