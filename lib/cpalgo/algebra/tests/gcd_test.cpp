#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/algebra/gcd.hpp"


TEST(GcdTest, ShouldHandleZero) {
    EXPECT_EQ(3ULL, gcd(3, 0));
    EXPECT_EQ(4ULL, gcd(0, 4));
    EXPECT_EQ(0ULL, gcd(0, 0));
}

TEST(GcdTest, ShouldComputeGreatestCommonDivisor) {
    EXPECT_EQ(1ULL, gcd(2, 3));
    EXPECT_EQ(1ULL, gcd(5, 7));

    EXPECT_EQ(4ULL, gcd(12, 8));
    EXPECT_EQ(2ULL, gcd(6, 8));
    EXPECT_EQ(9ULL, gcd(81, 36));
    EXPECT_EQ(21ULL, gcd(147, 105));
    EXPECT_EQ(20ULL, gcd(120, 140));
    EXPECT_EQ(1ULL, gcd(10213, 312));
    EXPECT_EQ(10ULL, gcd(10, 30));
}