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
    int N;
    long long MOD;
    std::vector<long long> factorial, inverse, factorial_inverse;

public:
    // O(N)
    // MOD should be a prime number
    Combination(int N = 10000000, long long MOD = 1000000007) {
        if (N < 2) throw;
        this->N = N;
        this->MOD = MOD;
        build();
    }

    // nCk
    // O(1)
    long long operator()(int n, int k) {
        if (n < 0 || k < 0) throw;
        if (n < k || n >= N) throw;
        return factorial[n] * (factorial_inverse[k] * factorial_inverse[n - k] % MOD) % MOD;
    }

    // O(1)
    int size() {
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
        for (int i = 2; i < N; ++i) {
            factorial[i] = factorial[i-1] * i % MOD;
            inverse[i] = MOD - inverse[MOD % i] * (MOD / i) % MOD;
            factorial_inverse[i] = factorial_inverse[i-1] * inverse[i] % MOD;
        }
    }
};