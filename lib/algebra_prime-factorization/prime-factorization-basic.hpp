#pragma once

#include <unordered_map>

// Prime Factorization
// Time: O(sqrt(N))
// Memory: O(1)
std::unordered_map<long long, int> prime_factorization(long long M) {
    std::unordered_map<long long, int> factors;
    long long mm = M;
    for (long long i = 2; i * i < M; ++i) {
        while (mm % i == 0) {
            ++factors[i];
            mm /= i;
        }
    }
    if (mm > 1) {
        ++factors[mm];
    }
    return factors;
}
