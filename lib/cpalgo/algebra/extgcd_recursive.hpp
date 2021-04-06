#pragma once

#include <cstdint>

// Extended Euclidean Algorithm (Recursive)
// Find x and y for given a and b
//    a * x + b * y = gcd(a,b)
//
// gcd(a, b)
//   = gcd(b, a%b)
//   = b * x1 + (a % b) * y1
//   = b * x1 + (a - floor(a / b) * b) * y1
//   = a * y1 + b * (x1 - floor(a / b) * y1)
//
// thus,
//   x = y1
//   y = x1 - y1 * (a / b)
//
// See:
//  - https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
//
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
//
inline int64_t extgcd(
    int64_t const a,
    int64_t const b,
    int64_t &x, int64_t &y
)
{
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int64_t x1, y1;
    int64_t g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}