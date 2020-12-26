#pragma once


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
//  - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
//  - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045
//
inline long long extgcd(long long a, long long b, long long &x, long long &y) {
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