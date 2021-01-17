#pragma once

#include <cstdint>
#include <utility>


// Binary GCD (a,b)
//
// The optimized Euclidean algorithm.
// The time complexity is same, but a lot faster than normal one that is using modulo operation.
//
// Time: O ( log(min(a,b)) )
// Space: O(1)
//
// See:
//  - https://cp-algorithms.com/algebra/euclid-algorithm.html
//
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_B
//
inline uint64_t gcd(uint64_t a, uint64_t b) {
    if (a == 0) return b;
    if (b == 0) return a;

    uint64_t g = 1;
    while (b > 0) {
        if ((a & 1) == 0 && (b & 1) == 0) {
            g <<= 1;
            a >>= 1;
            b >>= 1;
        } else if ((a & 1) == 0) {
            a >>= 1;
        } else if ((b & 1) == 0) {
            b >>= 1;
        } else {
            if (a > b) std::swap(a, b);
            b -= a;
        }
    }
    return g * a;
}