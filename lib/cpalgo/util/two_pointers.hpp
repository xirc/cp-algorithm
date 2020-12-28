#pragma once

#include <functional>

// Two Pointers
//
// Time: O(KN)
// Space: O(1)
//
// See:
//  - https://qiita.com/drken/items/ecd1a472d3a0e7db8dce
//
// Verified:
//  - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C
//
inline void iterate_with_two_pointers(
    size_t N,
    // O(K), l = [0,N), r = [0,N)
    std::function<bool(size_t, size_t)> should_move_right,
    // O(K), l = [0,N), r = [0,N]
    std::function<void(size_t, size_t)> pre_move_left,
    // O(K), l = [0,N), r = [0,N)
    std::function<void(size_t, size_t)> pre_move_right,
    // O(K), l = [0,N), r = [0,N]
    std::function<void(size_t, size_t)> update
) {
    size_t r = 0;
    for (size_t l = 0; l < N; ++l) {
        while (r < N && should_move_right(l,r)) {
            pre_move_right(l, r);
            ++r;
        }
        update(l, r);
        if (l == r) ++r;
        else pre_move_left(l, r);
    }
}