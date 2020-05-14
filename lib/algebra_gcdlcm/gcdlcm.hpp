#pragma once

#include <bits/stdc++.h>

// GCD (a,b)
// Time: O( log(min(a,b) )
long long gcd(long long a, long long b) {
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

// LCM (a,b)
// Time: O( log(min(a,b)) )
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}