#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "gcd.hpp"


TEST(GcdTest, ShouldHandleZero) {
    EXPECT_EQ(gcd(3, 0), 3ULL);
    EXPECT_EQ(gcd(0, 4), 4ULL);
    EXPECT_EQ(gcd(0, 0), 0ULL);
}

TEST(GcdTest, ShouldComputeGreatestCommonDivisor) {
    EXPECT_EQ(gcd(2, 3), 1ULL);
    EXPECT_EQ(gcd(5, 7), 1ULL);

    EXPECT_EQ(gcd(12, 8), 4ULL);
    EXPECT_EQ(gcd(6, 8), 2ULL);
    EXPECT_EQ(gcd(81, 36), 9ULL);
    EXPECT_EQ(gcd(147, 105), 21ULL);
    EXPECT_EQ(gcd(120, 140), 20ULL);
    EXPECT_EQ(gcd(10213, 312), 1ULL);
    EXPECT_EQ(gcd(10, 30), 10ULL);
}