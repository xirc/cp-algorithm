#pragma once

#include <limits>
#include <functional>
#include <cassert>


// Binary Search for an integer number
//
// Time: O(logN)
// Space: O(1)
//
// See:
//  - https://qiita.com/drken/items/97e37dd6143e33a64c8c
//
inline int64_t binary_search(
    std::function<bool(int64_t)> const& predicate,
    int64_t ng,
    int64_t ok
) {
    assert(!predicate(ng) && predicate(ok));
    while (abs(ok - ng) > 1) {
        auto m = (ok + ng) / 2;
        if (predicate(m)) ok = m;
        else ng = m;
    }
    return ok;
}
