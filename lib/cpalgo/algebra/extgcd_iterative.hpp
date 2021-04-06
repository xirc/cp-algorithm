#pragma once

#include <cstdint>
#include <tuple>


// Extended Euclidean Algorithm (Iterative)
// Find x and y for given a and b
//    a * x + b * y = gcd(a,b)
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
    int64_t &x,
    int64_t &y
)
{
    x = 1, y = 0;
    int64_t x1 = 0, y1 = 1;
    int64_t a1 = a, b1 = b;
    // a * x  + b * y  = a1
    // a * x1 + b * y1 = b1
    while (b1 > 0) {
        int64_t q = a1 / b1;
        std::tie(x, x1) = std::make_tuple(x1, x - q * x1);
        std::tie(y, y1) = std::make_tuple(y1, y - q * y1);
        std::tie(a1, b1) = std::make_tuple(b1, a1 - q * b1);
    }
    return a1;
}