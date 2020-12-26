#pragma once

#include "gcd.hpp"


// LCM (a,b)
// Time: O( log(min(a,b)) )
// See: https://cp-algorithms.com/algebra/euclid-algorithm.html
// Verified: https://www.codechef.com/problems/FLOW016
// Verified: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C
unsigned long long lcm(unsigned long long a, unsigned long long b) {
    return a / gcd(a, b) * b;
}
