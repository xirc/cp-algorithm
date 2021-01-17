#pragma once

#include <cstdint>
#include <vector>


// Prime Factorization
// Time: O(sqrt(N))
// Memory: O(1)
//
// See:
//  - https://cp-algorithms.com/algebra/factorization.html
//
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
//  - https://atcoder.jp/contests/abc110/tasks/abc110_d
//
inline std::vector<uint64_t> prime_factorization(uint64_t M) {
    std::vector<uint64_t> factors;
    for (uint64_t i = 2; i * i <= M; ++i) {
        while (M % i == 0) {
            factors.push_back(i);
            M /= i;
        }
    }
    if (M > 1) {
        factors.push_back(M);
    }
    return factors;
}
