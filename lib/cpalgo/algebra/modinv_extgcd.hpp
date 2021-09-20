#pragma once

#include "extgcd_iterative.hpp"


// Modular Multiplicative Inverse
//
// returns (a ** -1) mod m
//   where gcd(a,m) == 1
// returns -1 if gcd(a,m) != 1
//
// Complexity:
//   Time: O( log(min(a,b)) )
//   Space: O(1)
//
// Algorithm:
//   Extended Euclidean Algorithm
// a * x + m * y = 1
// (a * x + m * y = 1) mod m
// (a * x = 1) mod m
// (x = a ** -1) mod m
//
int64_t modinv(int64_t a, int64_t m) {
    int64_t x, y;
    auto g = extgcd(a, m, x, y);
    if (g != 1) {
        // There is no modular multiplicative inverse
        return -1;
    }
    return (x % m + m) % m;
}
