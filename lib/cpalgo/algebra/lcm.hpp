#pragma once

#include "gcd.hpp"


// LCM (a,b)
// Time: O( log(min(a,b)) )
// Verified: https://www.codechef.com/problems/FLOW016
// Verified: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}
