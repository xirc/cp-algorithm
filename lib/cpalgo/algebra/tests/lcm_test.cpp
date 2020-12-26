#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/algebra/lcm.hpp"


TEST(LcmTest, ShouldHandleZero) {
    EXPECT_EQ(0ULL, lcm(3, 0));
    EXPECT_EQ(0ULL, lcm(0, 4));
    EXPECT_EQ(0ULL, lcm(0, 0));
}

TEST(LcmTest, ShouldComputeLeastCommonMultiple) {
    EXPECT_EQ(6ULL, lcm(2, 3));
    EXPECT_EQ(35ULL, lcm(5, 7));

    EXPECT_EQ(24ULL, lcm(12, 8));
    EXPECT_EQ(24ULL, lcm(6, 8));
    EXPECT_EQ(324ULL, lcm(81, 36));
    EXPECT_EQ(735ULL, lcm(147, 105));
    EXPECT_EQ(840ULL, lcm(120, 140));
    EXPECT_EQ(3186456ULL, lcm(10213, 312));
    EXPECT_EQ(30ULL, lcm(10, 30));
}