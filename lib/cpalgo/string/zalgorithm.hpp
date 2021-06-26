#pragma once

#include <string>
#include <vector>

// Compute Z Array
//  Z[i] represents the length of the longest substring starting from S[i] which is a prefix of S[0..N).
//
// Complexity:
//  Time: O(N)
//  Space: O(N)
//
// See:
//  - https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/
//
// Verified:
//  - https://atcoder.jp/contests/abc141/tasks/abc141_e
//
inline std::vector<size_t> zalgorithm(std::string const& S) {
    size_t const N = S.size();
    std::vector<size_t> Z(N, 0);
    size_t L, R;
    L = R = 0;
    auto const extend_and_update = [&](int i) {
        while (R < N && S[R-L] == S[R]) ++R;
        Z[i] = R - L;
        --R;
    };
    for (size_t i = 0; i < N; ++i) {
        auto K = i - L;
        auto len = R - i + 1;
        if (i <= R && Z[K] < len) {
            Z[i] = Z[K];
        } else {
            if (i > R) L = R = i;
            else L = i;
            extend_and_update(i);
        }
    }
    return Z;
}
