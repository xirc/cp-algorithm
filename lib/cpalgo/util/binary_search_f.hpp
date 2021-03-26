#pragma once

#include <limits>
#include <functional>
#include <cassert>


// Binary Search for a floating point number
//
// Time: O(N)
// Space: O(1)
//
// NOTE:
// Use constant loop to avoid precision problems.
// Every loop reduces solution space by half.
// It would be better to pick a suitable loop count depending on a problem.
//
// Verified:
// - https://atcoder.jp/contests/abc034/tasks/abc034_d
//
inline long double binary_search_f(
    std::function<bool(long double)> const& predicate,
    long double ng,
    long double ok,
    const size_t N = 200
) {
    assert(!predicate(ng) && predicate(ok));
    for (size_t i = 0; i < N; ++i) {
        auto m = (ok + ng) / 2;
        if (predicate(m)) ok = m;
        else ng = m;
    }
    return ok;
}