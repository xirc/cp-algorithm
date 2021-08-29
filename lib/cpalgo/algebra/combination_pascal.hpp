#pragma once

#include <cstdint>
#include <limits>
#include <stdexcept>
#include <vector>


// Binomial Coefficient (Combination) in modulo M
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
template<uint64_t MOD = std::numeric_limits<uint64_t>::max()>
class CombinationPascal {
    size_t N;
    std::vector<std::vector<uint64_t>> comb;

public:
    // Time: O(N^2)
    CombinationPascal(
        size_t const N = 1000
    )
    {
        build(N);
    }
    // Time: O(N^2)
    void build(size_t const N) {
        this->N = N;
        comb.assign(N + 1, std::vector<uint64_t>(N + 1, 0));
        comb[0][0] = 1;
        for (size_t n = 1; n <= N; ++n) {
            comb[n][0] = 1;
            for (size_t k = 1; k <= N; ++k) {
                comb[n][k] = (comb[n-1][k-1] + comb[n-1][k]) % MOD;
            }
        }
    }
    // nCk
    // n = [0,N], k = [0,n]
    // Time: O(1)
    uint64_t C(size_t const n, size_t const k) const {
        if (k > n) throw std::out_of_range("k");
        if (n > N) throw std::out_of_range("n");
        return comb[n][k];
    }
    // nHk
    // H(n,k) = C(n+k-1,k)
    // n = [0,N-k+1], k = [0,N]
    // Time: O(1)
    uint64_t H(size_t const n, size_t const k) const {
        if (n == 0 && k == 0) return 1;
        return C(n+k-1,k);
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }
};
