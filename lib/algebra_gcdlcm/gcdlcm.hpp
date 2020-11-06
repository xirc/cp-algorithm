#pragma once

#include <bits/stdc++.h>

// GCD (a,b)
// Time: O( log(min(a,b)) )
// Verified: https://www.codechef.com/problems/FLOW016
// Verified: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_B
long long gcd(long long a, long long b) {
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

// LCM (a,b)
// Time: O( log(min(a,b)) )
// Verified: https://www.codechef.com/problems/FLOW016
// Verified: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

// Binary GCD (a,b)
// Time: O ( log(min(a,b)) )
// The optimized Euclidean algorithm.
// The time complexity is same, but a lot faster than normal one that is using modulo operation.
// Verified: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_B
long long bingcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;

    long long g = 1;
    while (b > 0) {
        if (a & 1 == 0 && b & 1 == 0) {
            g <<= 1;
        } else if (a & 1 == 0) {
            a >>= 1;
        } else if (b & 1 == 0) {
            b >>= 1;
        } else {
            if (a < b) std::swap(a, b);
            a -= b;
        }
    }
    return g * a;
}