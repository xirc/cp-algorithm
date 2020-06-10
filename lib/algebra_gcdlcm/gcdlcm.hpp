#pragma once

#include <bits/stdc++.h>

// GCD (a,b)
// Time: O( log(min(a,b) )
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
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}