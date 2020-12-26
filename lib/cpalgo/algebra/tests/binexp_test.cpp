#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/algebra/binexp.hpp"

TEST(BinExpTest, ComputePowerOfTwo) {
    EXPECT_EQ(binexp<int>(2, 0, 1), 1);
    EXPECT_EQ(binexp<int>(2, 10, 1), 1024);
    EXPECT_EQ(binexp<int>(2, 31, 1), (1 << 31));

    EXPECT_EQ(binexp<long long>(2, 0, 1), 1);
    EXPECT_EQ(binexp<long long>(2, 10, 1), 1024);
    EXPECT_EQ(binexp<long long>(2, 61, 1), (1L << 61));
}

TEST(BinExpTest, ComputePowerOfNumber) {
    EXPECT_EQ(binexp<int>(3, 0, 1), 1);
    EXPECT_EQ(binexp<int>(3, 4, 1), 81);
    EXPECT_EQ(binexp<int>(5, 3, 1), 125);
    EXPECT_EQ(binexp<int>(123, 3, 1), 123*123*123);
}

TEST(BinExpTest, ComputeWithCustomOperator) {
    EXPECT_EQ(binexp<int>(1, 0, 0, std::bit_xor<int>()), 0);
    EXPECT_EQ(binexp<int>(1, 1, 0, std::bit_xor<int>()), 1);
    EXPECT_EQ(binexp<int>(1, 2, 0, std::bit_xor<int>()), 0);
    EXPECT_EQ(binexp<int>(11, 1, 0, std::bit_xor<int>()), 11);
    EXPECT_EQ(binexp<int>(11, 0, 0, std::bit_xor<int>()), 0);
    EXPECT_EQ(binexp<int>(11, 98, 0, std::bit_xor<int>()), 0);
    EXPECT_EQ(binexp<int>(11, 99, 0, std::bit_xor<int>()), 11);
}

TEST(BinExpTest, ComputeWithLargeExponent) {
    EXPECT_EQ(binexp<long long>(1, 1234567890L, 0, std::plus<long long>()), 1234567890L);
    EXPECT_EQ(binexp<long long>(1, std::numeric_limits<long long>::max(), 0, std::plus<long long>()), std::numeric_limits<long long>::max());
    EXPECT_EQ(binexp<long long>(2, 1234567890L, 0, std::plus<long long>()), 1234567890L*2);
    EXPECT_EQ(binexp<long long>(1234567890L, 1234567890L, 0, std::plus<long long>()), 1234567890L*1234567890L);
    EXPECT_EQ(binexp<long long>(1, 1234567890L, 0, std::bit_xor<long long>()), 0);
    EXPECT_EQ(binexp<long long>(1, 1234567891L, 0, std::bit_xor<long long>()), 1);
}