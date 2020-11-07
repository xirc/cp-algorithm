#pragma

#include <bits/stdc++.h>

// Extended Euclidean Algorithm (Recursive)
// Find x and y for given a and b
//    a * x + b * y = gcd(a,b)
//
// gcd(a, b)
//   = gcd(b, a%b)
//   = b * x1 + (a % b) * y1
//   = b * x1 + (a - floor(a / b) * b) * y1
//   = a * y1 + b * (x1 - floor(a / b) * y1)
//
// thus,
//   x = y1
//   y = x1 - y1 * (a / b)
//
// Verified:
//  - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045
//
long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

// Extended Euclidean Algorithm (Iterative)
// Find x and y for given a and b
//    a * x + b * y = gcd(a,b)
//
// Verified:
//  - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045
//
long long extgcdi(long long a, long long b, long long &x, long long &y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
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