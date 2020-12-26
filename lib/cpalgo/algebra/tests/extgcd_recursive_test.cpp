#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/algebra/extgcd_recursive.hpp"


TEST(ExtgcdRecursiveTest, ShouldComputeExtendedEuclidean) {
    long long x, y;
    long long g;

    g = extgcd(4, 12, x, y);
    EXPECT_EQ(1LL, x) << "  where 4 * x + 12 * y = g";
    EXPECT_EQ(0LL, y) << "  where 4 * x + 12 * y = g";
    EXPECT_EQ(4LL, g) << "  where 4 * x + 12 * y = g";

    g = extgcd(3, 8, x, y);
    EXPECT_EQ( 3LL, x) << "  where 3 * x + 8 * y = g";
    EXPECT_EQ(-1LL, y) << "  where 3 * x + 8 * y = g";
    EXPECT_EQ( 1LL, g) << "  where 3 * x + 8 * y = g";

    g = extgcd(4, 6, x, y);
    EXPECT_EQ(-1LL, x) << "  where 4 * x + 6 * y = g";
    EXPECT_EQ( 1LL, y) << "  where 4 * x + 6 * y = g";
    EXPECT_EQ( 2LL, g) << "  where 4 * x + 6 * y = g";

    g = extgcd(17, 17, x, y);
    EXPECT_EQ( 0LL, x) << "  where 17 * x + 17 * y = g";
    EXPECT_EQ( 1LL, y) << "  where 17 * x + 17 * y = g";
    EXPECT_EQ(17LL, g) << "  where 17 * x + 17 * y = g";
}