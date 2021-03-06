#pragma once

#include "gcd.hpp"


// LCM (a,b)
//
// Time: O( log(min(a,b)) )
//
// See:
//  - https://cp-algorithms.com/algebra/euclid-algorithm.html
//
// Verified
//  - https://www.codechef.com/problems/FLOW016
//  - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C
//
inline uint64_t lcm(uint64_t const a, uint64_t const b) {
    if (a == 0 && b == 0) return 0;
    return a / gcd(a, b) * b;
}
