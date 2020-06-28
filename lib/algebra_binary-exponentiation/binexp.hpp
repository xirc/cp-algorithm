#pragma once

#include <functional>

// Binary Exponentation
// Time: O(logN)
// Memory: O(1)
template<class T>
T binexp(
    T a,
    long long n,
    const T& id,
    const std::function<T(const T&, const T&)> op = std::multiplies<T>()
) {
    if (n < 0) throw;

    T ans = id;
    while (n > 0) {
        if (n & 1) {
            ans = op(ans, a);
        }
        a = op(a, a);
        n >>= 1;
    }
    return ans;
}