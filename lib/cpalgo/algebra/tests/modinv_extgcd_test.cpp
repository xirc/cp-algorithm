#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/algebra/modinv_extgcd.hpp"

TEST(ModinvExtgcdTest, ComputeInverseInModulo7) {
    EXPECT_EQ(1, modinv(1, 7));
    EXPECT_EQ(4, modinv(2, 7));
    EXPECT_EQ(5, modinv(3, 7));
    EXPECT_EQ(2, modinv(4, 7));
    EXPECT_EQ(3, modinv(5, 7));
    EXPECT_EQ(6, modinv(6, 7));
}

TEST(ModinvExtgcdTest, ComputeInverseInModulo9) {
    EXPECT_EQ( 1, modinv(1, 9));
    EXPECT_EQ( 5, modinv(2, 9));
    EXPECT_EQ(-1, modinv(3, 9));
    EXPECT_EQ( 7, modinv(4, 9));
    EXPECT_EQ( 2, modinv(5, 9));
    EXPECT_EQ(-1, modinv(6, 9));
    EXPECT_EQ( 4, modinv(7, 9));
    EXPECT_EQ( 8, modinv(8, 9));
}

TEST(ModinvExtgcdTest, ComputeInverseInModulo13) {
    EXPECT_EQ( 1, modinv( 1, 13));
    EXPECT_EQ( 7, modinv( 2, 13));
    EXPECT_EQ( 9, modinv( 3, 13));
    EXPECT_EQ(10, modinv( 4, 13));
    EXPECT_EQ( 8, modinv( 5, 13));
    EXPECT_EQ(11, modinv( 6, 13));
    EXPECT_EQ( 2, modinv( 7, 13));
    EXPECT_EQ( 5, modinv( 8, 13));
    EXPECT_EQ( 3, modinv( 9, 13));
    EXPECT_EQ( 4, modinv(10, 13));
    EXPECT_EQ( 6, modinv(11, 13));
    EXPECT_EQ(12, modinv(12, 13));
}

