#pragma once

#include <functional>
#include <stdexcept>

// Iterates subsets of given bitset `S`.
//
// S = b0101
// bs = { 0101, 0100, 0001, 0000 }
//
// Time: O(2**M)
//   where M is the bit count of the given bitset
//
inline void iterate_subsets(
    int S,
    std::function<void(int)> const& f
) {
    if (S < 0) throw std::out_of_range("S");
    for (auto bs = S; true; bs = (bs - 1) & S) {
        f(bs);
        if (bs == 0) break;
    }
}
