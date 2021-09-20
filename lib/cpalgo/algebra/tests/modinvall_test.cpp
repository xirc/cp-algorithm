#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/algebra/modinvall.hpp"

TEST(ModInvAllTest, ComputeAllInverseInModulo7) {
    auto inv = modinvall(7);
    EXPECT_EQ(1, inv[1]);
    EXPECT_EQ(4, inv[2]);
    EXPECT_EQ(5, inv[3]);
    EXPECT_EQ(2, inv[4]);
    EXPECT_EQ(3, inv[5]);
    EXPECT_EQ(6, inv[6]);
}

TEST(ModinvExtgcdTest, ComputeAllInverseInModulo13) {
    auto inv = modinvall(13);
    EXPECT_EQ( 1,  inv[1]);
    EXPECT_EQ( 7,  inv[2]);
    EXPECT_EQ( 9,  inv[3]);
    EXPECT_EQ(10,  inv[4]);
    EXPECT_EQ( 8,  inv[5]);
    EXPECT_EQ(11,  inv[6]);
    EXPECT_EQ( 2,  inv[7]);
    EXPECT_EQ( 5,  inv[8]);
    EXPECT_EQ( 3,  inv[9]);
    EXPECT_EQ( 4, inv[10]);
    EXPECT_EQ( 6, inv[11]);
    EXPECT_EQ(12, inv[12]);
}

