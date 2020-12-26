#pragma once

#include <bits/stdc++.h>

// Extended Euclidean Algorithm (Iterative)
// Find x and y for given a and b
//    a * x + b * y = gcd(a,b)
//
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
//  - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045
//
long long extgcd(long long a, long long b, long long &x, long long &y) {
    x = 1, y = 0;
    long long x1 = 0, y1 = 1, a1 = a, b1 = b;
    // a * x  + b * y  = a1
    // a * x1 + b * y1 = b1
    while (b1 > 0) {
        long long q = a1 / b1;
        std::tie(x, x1) = std::make_tuple(x1, x - q * x1);
        std::tie(y, y1) = std::make_tuple(y1, y - q * y1);
        std::tie(a1, b1) = std::make_tuple(b1, a1 - q * b1);
    }
    return a1;
}