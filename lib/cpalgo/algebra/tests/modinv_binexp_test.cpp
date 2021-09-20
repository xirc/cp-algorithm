#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/algebra/modinv_binexp.hpp"

TEST(ModinvBinexpTest, ComputeInverseInModulo7) {
    EXPECT_EQ(1, modinv_binexp(1, 7));
    EXPECT_EQ(4, modinv_binexp(2, 7));
    EXPECT_EQ(5, modinv_binexp(3, 7));
    EXPECT_EQ(2, modinv_binexp(4, 7));
    EXPECT_EQ(3, modinv_binexp(5, 7));
    EXPECT_EQ(6, modinv_binexp(6, 7));
}

TEST(ModinvBinexpTest, ComputeInverseInModulo13) {
    EXPECT_EQ( 1, modinv_binexp( 1, 13));
    EXPECT_EQ( 7, modinv_binexp( 2, 13));
    EXPECT_EQ( 9, modinv_binexp( 3, 13));
    EXPECT_EQ(10, modinv_binexp( 4, 13));
    EXPECT_EQ( 8, modinv_binexp( 5, 13));
    EXPECT_EQ(11, modinv_binexp( 6, 13));
    EXPECT_EQ( 2, modinv_binexp( 7, 13));
    EXPECT_EQ( 5, modinv_binexp( 8, 13));
    EXPECT_EQ( 3, modinv_binexp( 9, 13));
    EXPECT_EQ( 4, modinv_binexp(10, 13));
    EXPECT_EQ( 6, modinv_binexp(11, 13));
    EXPECT_EQ(12, modinv_binexp(12, 13));
}
