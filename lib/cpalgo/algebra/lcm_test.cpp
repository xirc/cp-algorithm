#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "lcm.hpp"


TEST(LcmTest, ShouldHandleZero) {
    EXPECT_EQ(lcm(3, 0), 0ULL);
    EXPECT_EQ(lcm(0, 4), 0ULL);
    EXPECT_EQ(lcm(0, 0), 0ULL);
}

TEST(LcmTest, ShouldComputeLeastCommonMultiple) {
    EXPECT_EQ(lcm(2, 3), 6ULL);
    EXPECT_EQ(lcm(5, 7), 35ULL);

    EXPECT_EQ(lcm(12, 8), 24ULL);
    EXPECT_EQ(lcm(6, 8), 24ULL);
    EXPECT_EQ(lcm(81, 36), 324ULL);
    EXPECT_EQ(lcm(147, 105), 735ULL);
    EXPECT_EQ(lcm(120, 140), 840ULL);
    EXPECT_EQ(lcm(10213, 312), 3186456ULL);
    EXPECT_EQ(lcm(10, 30), 30ULL);
}