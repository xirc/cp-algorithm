#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/algebra/combination_basic.hpp"


TEST(CombinationBasicTest, ShouldComputeBinomialCoefficients) {
    CombinationBasic<> comb(20);

    EXPECT_EQ(1ULL, comb(0, 0));

    EXPECT_EQ(1ULL, comb(1, 0));
    EXPECT_EQ(1ULL, comb(1, 1));

    EXPECT_EQ(1ULL, comb(2, 0));
    EXPECT_EQ(2ULL, comb(2, 1));
    EXPECT_EQ(1ULL, comb(2, 2));

    EXPECT_EQ(1ULL, comb(3, 0));
    EXPECT_EQ(3ULL, comb(3, 1));
    EXPECT_EQ(3ULL, comb(3, 2));
    EXPECT_EQ(1ULL, comb(3, 3));

    EXPECT_EQ(1ULL, comb(4, 0));
    EXPECT_EQ(4ULL, comb(4, 1));
    EXPECT_EQ(6ULL, comb(4, 2));
    EXPECT_EQ(4ULL, comb(4, 3));
    EXPECT_EQ(1ULL, comb(4, 4));

    EXPECT_EQ( 1ULL, comb(5, 0));
    EXPECT_EQ( 5ULL, comb(5, 1));
    EXPECT_EQ(10ULL, comb(5, 2));
    EXPECT_EQ(10ULL, comb(5, 3));
    EXPECT_EQ( 5ULL, comb(5, 4));
    EXPECT_EQ( 1ULL, comb(5, 5));

    EXPECT_EQ( 1ULL, comb(6, 0));
    EXPECT_EQ( 6ULL, comb(6, 1));
    EXPECT_EQ(15ULL, comb(6, 2));
    EXPECT_EQ(20ULL, comb(6, 3));
    EXPECT_EQ(15ULL, comb(6, 4));
    EXPECT_EQ( 6ULL, comb(6, 5));
    EXPECT_EQ( 1ULL, comb(6, 6));

    EXPECT_EQ( 1ULL, comb(7, 0));
    EXPECT_EQ( 7ULL, comb(7, 1));
    EXPECT_EQ(21ULL, comb(7, 2));
    EXPECT_EQ(35ULL, comb(7, 3));
    EXPECT_EQ(35ULL, comb(7, 4));
    EXPECT_EQ(21ULL, comb(7, 5));
    EXPECT_EQ( 7ULL, comb(7, 6));
    EXPECT_EQ( 1ULL, comb(7, 7));

    EXPECT_EQ(     1ULL, comb(20, 0));
    EXPECT_EQ(    20ULL, comb(20, 1));
    EXPECT_EQ(   190ULL, comb(20, 2));
    EXPECT_EQ(  1140ULL, comb(20, 3));
    EXPECT_EQ(  4845ULL, comb(20, 4));
    EXPECT_EQ( 15504ULL, comb(20, 5));
    EXPECT_EQ( 38760ULL, comb(20, 6));
    EXPECT_EQ( 77520ULL, comb(20, 7));
    EXPECT_EQ(125970ULL, comb(20, 8));
    EXPECT_EQ(167960ULL, comb(20, 9));
    EXPECT_EQ(184756ULL, comb(20, 10));
    EXPECT_EQ(167960ULL, comb(20, 11));
    EXPECT_EQ(125970ULL, comb(20, 12));
    EXPECT_EQ( 77520ULL, comb(20, 13));
    EXPECT_EQ( 38760ULL, comb(20, 14));
    EXPECT_EQ( 15504ULL, comb(20, 15));
    EXPECT_EQ(  4845ULL, comb(20, 16));
    EXPECT_EQ(  1140ULL, comb(20, 17));
    EXPECT_EQ(   190ULL, comb(20, 18));
    EXPECT_EQ(    20ULL, comb(20, 19));
    EXPECT_EQ(     1ULL, comb(20, 20));

    EXPECT_THROW({
        // n > N
        comb(21, 0);
    }, std::out_of_range);

    EXPECT_THROW({
        // k > n
        comb(6, 7);
    }, std::out_of_range);

}
