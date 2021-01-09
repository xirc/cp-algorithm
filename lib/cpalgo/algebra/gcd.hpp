#pragma once

#include <utility>


// GCD (a,b)
//
// Time: O( log(min(a,b)) )
// Space: O(1)
//
// See:
//  - https://cp-algorithms.com/algebra/euclid-algorithm.html
//
// Verified:
//  - https://www.codechef.com/problems/FLOW016
//  - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_B
//
inline unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}
