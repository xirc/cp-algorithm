#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/util/bitops.hpp"

using namespace std;

TEST(BitOpsTest, IterateSubsets) {

    int S = (1 << 0) | (1 << 2) | (1 << 3);
    set<int> subsets;
    iterate_subsets(S, [&](int bs) {
        subsets.insert(bs);
    });
    set<int> expected_subsets = {
        (1 << 0) | (1 << 2) | (1 << 3),
        (1 << 2) | (1 << 3),
        (1 << 0) | (1 << 3),
        (1 << 3),
        (1 << 0) | (1 << 2),
        (1 << 2),
        (1 << 0),
        0
    };

    EXPECT_EQ(expected_subsets, subsets);

}