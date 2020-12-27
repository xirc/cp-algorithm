#include <bits/stdc++.h>
#include "cpalgo/util/bigint.hpp"

using namespace std;

#define PRINT(x) cout << #x": "<< (x) << endl;

int main() {
    bigint a, b(1234567890);
    a = bigint::parse("-100000000000000000000");

    PRINT(a);
    PRINT(b);
    PRINT(-a);
    PRINT(-b);
    PRINT(a.abs());
    PRINT(b.abs());
    PRINT(a<b);
    PRINT(a>b);
    PRINT(a<=b);
    PRINT(a>=b);
    PRINT(a!=b);
    PRINT(a==b);
    PRINT(a+b);
    PRINT(a-b);
    PRINT(a*b);
    PRINT(a/b);
    PRINT(a%b);
    PRINT(to_string(a));
    PRINT(to_string(b));
    PRINT(a.digits());
    PRINT(b.digits());
    PRINT(a.trailing_zeros());
    PRINT(b.trailing_zeros());
    for (size_t i = 0, n = a.digits(); i < n; ++i) {
        cout << "a[" << i << "]: " << a[i] << endl;
    }
    for (size_t i = 0, n = b.digits(); i < n; ++i) {
        cout << "b[" << i << "]: " << b[i] << endl;
    }

    return 0;
}