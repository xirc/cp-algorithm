#pragma once

#include <utility>


// Binary GCD (a,b)
// Time: O ( log(min(a,b)) )
// The optimized Euclidean algorithm.
// The time complexity is same, but a lot faster than normal one that is using modulo operation.
// See: https://cp-algorithms.com/algebra/euclid-algorithm.html
// Verified: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_B
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (a == 0) return b;
    if (b == 0) return a;

    unsigned long long g = 1;
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