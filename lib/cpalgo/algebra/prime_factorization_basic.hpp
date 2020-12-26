#pragma once

#include <unordered_map>
#include <vector>


// Prime Factorization
// Time: O(sqrt(N))
// Memory: O(1)
//
// See:
//  - https://cp-algorithms.com/algebra/factorization.html
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
//
inline std::vector<unsigned long long> prime_factorization(unsigned long long M) {
    std::vector<unsigned long long> factors;
    for (unsigned long long i = 2; i * i < M; ++i) {
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
