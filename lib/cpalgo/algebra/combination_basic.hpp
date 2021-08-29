#pragma once

#include <cstdint>
#include <stdexcept>
#include <vector>


// Binomial Coefficient (Combination) in modulo M
//
// Constraints:
//   N <= 10^7
//
// Time: O(N)
// Space: O(N)
//
// NOTE:
// - M should be a prime number
//
// See:
// - https://algo-logic.info/combination/#toc_id_1_1
//
// Verified
// - https://atcoder.jp/contests/abc034/tasks/abc034_c
// - https://atcoder.jp/contests/abc110/tasks/abc110_d
//
template <uint64_t MOD = 1000000007>
class CombinationBasic {
    size_t N;
    std::vector<uint64_t> factorial, inverse, factorial_inverse;

public:
    // Time: O(N)
    CombinationBasic(
        size_t const N = 10000000
    )
    {
        build(N);
    }
    // Time: O(N)
    void build(size_t const N) {
        this->N = N;

        factorial.assign(N + 1, 0);
        factorial_inverse.assign(N + 1, 0);
        inverse.assign(N + 1, 0);
        factorial[0] = factorial[1] = 1;
        factorial_inverse[0] = factorial_inverse[1] = 1;
        inverse[0] = 0;
        inverse[1] = 1;
        for (size_t i = 2; i <= N; ++i) {
            factorial[i] = factorial[i-1] * i % MOD;
            inverse[i] = MOD - inverse[MOD % i] * (MOD / i) % MOD;
            factorial_inverse[i] = factorial_inverse[i-1] * inverse[i] % MOD;
        }
    }
    // nCk
    // n = [0,N], k = [0,n]
    // Time: O(1)
    uint64_t operator()(size_t const n, size_t const k) const {
        if (k > n) throw std::out_of_range("k");
        if (n > N) throw std::out_of_range("n");
        return factorial[n] * (factorial_inverse[k] * factorial_inverse[n - k] % MOD) % MOD;
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }
};