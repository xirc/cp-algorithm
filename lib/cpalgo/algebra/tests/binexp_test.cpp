#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/algebra/binexp.hpp"

TEST(BinExpTest, ComputePowerOfTwo) {
    EXPECT_EQ(1, binexp<int>(2, 0, 1));
    EXPECT_EQ(1024, binexp<int>(2, 10, 1));
    EXPECT_EQ(1 << 31, binexp<int>(2, 31, 1));

    EXPECT_EQ(1LL, binexp<long long>(2, 0, 1));
    EXPECT_EQ(1024LL, binexp<long long>(2, 10, 1));
    EXPECT_EQ(1LL << 61, binexp<long long>(2, 61, 1));
}

TEST(BinExpTest, ComputePowerOfNumber) {
    EXPECT_EQ(1, binexp<int>(3, 0, 1));
    EXPECT_EQ(81, binexp<int>(3, 4, 1));
    EXPECT_EQ(125, binexp<int>(5, 3, 1));
    EXPECT_EQ(1860867, binexp<int>(123, 3, 1));
}

TEST(BinExpTest, ComputeWithCustomOperator) {
    EXPECT_EQ(0, binexp<int>(1, 0, 0, std::bit_xor<int>()));
    EXPECT_EQ(1, binexp<int>(1, 1, 0, std::bit_xor<int>()));
    EXPECT_EQ(0, binexp<int>(1, 2, 0, std::bit_xor<int>()));
    EXPECT_EQ(11, binexp<int>(11, 1, 0, std::bit_xor<int>()));
    EXPECT_EQ(0, binexp<int>(11, 0, 0, std::bit_xor<int>()));
    EXPECT_EQ(0, binexp<int>(11, 98, 0, std::bit_xor<int>()));
    EXPECT_EQ(11, binexp<int>(11, 99, 0, std::bit_xor<int>()));
}

TEST(BinExpTest, ComputeWithLargeExponent) {
    EXPECT_EQ(1234567890LL, binexp<long long>(1, 1234567890, 0, std::plus<long long>()));
    EXPECT_EQ(
        std::numeric_limits<long long>::max(),
        binexp<long long>(1, std::numeric_limits<long long>::max(), 0, std::plus<long long>())
    );
    EXPECT_EQ(2469135780LL, binexp<long long>(2, 1234567890L, 0, std::plus<long long>()));
    EXPECT_EQ(1524157875019052100LL, binexp<long long>(1234567890L, 1234567890L, 0, std::plus<long long>()));
    EXPECT_EQ(0LL, binexp<long long>(1, 1234567890L, 0, std::bit_xor<long long>()));
    EXPECT_EQ(1LL, binexp<long long>(1, 1234567891L, 0, std::bit_xor<long long>()));
}