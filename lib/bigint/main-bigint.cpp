#include <iostream>
#include "bigint.hpp"

#define PRINT(x) std::cout << #x": "<< (x) << std::endl;

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
    for (int i = 0, n = a.digits(); i < n; ++i) {
        std::cout << "a[" << i << "]: " << a[i] << std::endl;
    }
    for (int i = 0, n = b.digits(); i < n; ++i) {
        std::cout << "b[" << i << "]: " << b[i] << std::endl;
    }

    return 0;
}