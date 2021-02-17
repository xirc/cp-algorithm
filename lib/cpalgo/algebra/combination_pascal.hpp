#pragma once

#include <cstdint>
#include <limits>
#include <stdexcept>
#include <vector>


// Binomial Coefficient (Combination) modulo M
//
// Constraints:
//   N <= 10^3 ~ 10^4
//
// Time: O(N*2)
// Space: O(N*2)
//
// NOTE:
// - M can be a composite number
//
// See:
// - https://en.wikipedia.org/wiki/Pascal%27s_triangle
// - https://cp-algorithms.com/combinatorics/binomial-coefficients.html#toc-tgt-3
// - https://algo-logic.info/combination/#toc_id_1_3
//
// Verified
// - https://atcoder.jp/contests/abc057/tasks/abc057_d
//
class CombinationPascal {
    size_t N;
    uint64_t MOD;
    std::vector<std::vector<uint64_t>> C;

public:
    // Time: O(N^2)
    CombinationPascal(
        size_t const N = 1000,
        uint64_t const MOD = std::numeric_limits<uint64_t>::max()
    )
    {
        build(N, MOD);
    }
    // Time: O(N^2)
    void build(size_t const N, uint64_t const MOD) {
        this->N = N;
        this->MOD = MOD;
        if (N == 0) return;
        C.assign(N, std::vector<uint64_t>(N, 0));
        C[0][0] = 1;
        for (size_t n = 1; n < N; ++n) {
            C[n][0] = 1;
            for (size_t k = 1; k < N; ++k) {
                C[n][k] = (C[n-1][k-1] + C[n-1][k]) % MOD;
            }
        }
    }
    // nCk
    // n = [0,N), k = [0,n]
    // Time: O(1)
    uint64_t operator()(size_t const n, size_t const k) const {
        if (k > n) throw std::out_of_range("k");
        if (n >= N) throw std::out_of_range("n");
        return C[n][k];
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }
};