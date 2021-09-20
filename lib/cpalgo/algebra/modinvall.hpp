#pragma once

#include <vector>


// Modular Multiplicative Inverse for every number modulo `m`
//   `m` must be an prime number
// undefined behavior if `m` is not the prime number
//
// Complexity:
//   Time: O(M)
//   Space: O(M)
//
// Algorithm:
//   m mod i = m - floor(m / i) * i
//   m mod i = { m - floor(m / i) * i }   mod m
//   m mod i = { - floor(m / i) * i }   mod m
//   (m mod i) * (i ** -1) * ((m mod i) ** -1) =
//       { - floor(m / i) * i * (i ** -1) * ((m mod i) ** 0) }   mod m
//   i ** -1 =
//     - floor(m / i) * { (m mod i) ** - 1 }   mod m
//   i ** -1 =
//     m - floor(m / i) * { (m mod i) ** -1 }   mod m
//
// NOTE:
//  inverse[M % i] can be calculated using inverse[1..i-1]
//  - i < M
//  - M % i < i
//  - M % i != 0 if M is the prime number
//
std::vector<int> modinvall(int M) {
    std::vector<int> inverse(M, 0);
    // inserve[0] is undefined
    inverse[1] = 1;
    for (int i = 2; i < M; ++i) {
        inverse[i] = M - (M / i) * inverse[M % i] % M;
    }
    return inverse;
}
