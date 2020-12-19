#pragma once

#include <unordered_map>

// Prime Factorization
// Time: O(sqrt(N))
// Memory: O(1)
//
// Verified:
// - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
//
std::vector<long long> prime_factorization(long long M) {
    std::vector<long long> factors;
    long long mm = M;
    for (long long i = 2; i * i < M; ++i) {
        while (mm % i == 0) {
            factors.push_back(i);
            mm /= i;
        }
    }
    if (mm > 1) {
        factors.push_back(mm);
    }
    return factors;
}
