#pragma once

#include <vector>


// Binomial Coefficient (Combination) modulo M
// Time: O(N)
// Memory: O(N)
//   where N <= 10^7
//
// See:
// - https://algo-logic.info/combination/#toc_id_1_1
//
// Verified
// - https://atcoder.jp/contests/abc110/tasks/abc110_d
//
class Combination {
    size_t N;
    unsigned long long MOD;
    std::vector<unsigned long long> factorial, inverse, factorial_inverse;

public:
    // O(N)
    // MOD should be a prime number
    Combination(size_t N = 10000000, unsigned long long MOD = 1000000007) {
        this->N = N;
        this->MOD = MOD;
        build();
    }

    // nCk
    // O(1)
    unsigned long long operator()(size_t n, size_t k) {
        if (n < k || n >= N) throw;
        return factorial[n] * (factorial_inverse[k] * factorial_inverse[n - k] % MOD) % MOD;
    }

    // O(1)
    size_t size() {
        return N;
    }

private:
    void build() {
        factorial.assign(N, 0);
        factorial_inverse.assign(N, 0);
        inverse.assign(N, 0);
        factorial[0] = factorial[1] = 1;
        factorial_inverse[0] = factorial_inverse[1] = 1;
        inverse[0] = 0;
        inverse[1] = 1;
        for (size_t i = 2; i < N; ++i) {
            factorial[i] = factorial[i-1] * i % MOD;
            inverse[i] = MOD - inverse[MOD % i] * (MOD / i) % MOD;
            factorial_inverse[i] = factorial_inverse[i-1] * inverse[i] % MOD;
        }
    }
};