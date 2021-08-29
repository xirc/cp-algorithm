#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/algebra/combination_pascal.hpp"


TEST(CombinationPascalTest, ShouldComputeBinomialCoefficients) {
    CombinationPascal<> comb(20);

    EXPECT_EQ(1ULL, comb.C(0, 0));

    EXPECT_EQ(1ULL, comb.C(1, 0));
    EXPECT_EQ(1ULL, comb.C(1, 1));

    EXPECT_EQ(1ULL, comb.C(2, 0));
    EXPECT_EQ(2ULL, comb.C(2, 1));
    EXPECT_EQ(1ULL, comb.C(2, 2));

    EXPECT_EQ(1ULL, comb.C(3, 0));
    EXPECT_EQ(3ULL, comb.C(3, 1));
    EXPECT_EQ(3ULL, comb.C(3, 2));
    EXPECT_EQ(1ULL, comb.C(3, 3));

    EXPECT_EQ(1ULL, comb.C(4, 0));
    EXPECT_EQ(4ULL, comb.C(4, 1));
    EXPECT_EQ(6ULL, comb.C(4, 2));
    EXPECT_EQ(4ULL, comb.C(4, 3));
    EXPECT_EQ(1ULL, comb.C(4, 4));

    EXPECT_EQ( 1ULL, comb.C(5, 0));
    EXPECT_EQ( 5ULL, comb.C(5, 1));
    EXPECT_EQ(10ULL, comb.C(5, 2));
    EXPECT_EQ(10ULL, comb.C(5, 3));
    EXPECT_EQ( 5ULL, comb.C(5, 4));
    EXPECT_EQ( 1ULL, comb.C(5, 5));

    EXPECT_EQ( 1ULL, comb.C(6, 0));
    EXPECT_EQ( 6ULL, comb.C(6, 1));
    EXPECT_EQ(15ULL, comb.C(6, 2));
    EXPECT_EQ(20ULL, comb.C(6, 3));
    EXPECT_EQ(15ULL, comb.C(6, 4));
    EXPECT_EQ( 6ULL, comb.C(6, 5));
    EXPECT_EQ( 1ULL, comb.C(6, 6));

    EXPECT_EQ( 1ULL, comb.C(7, 0));
    EXPECT_EQ( 7ULL, comb.C(7, 1));
    EXPECT_EQ(21ULL, comb.C(7, 2));
    EXPECT_EQ(35ULL, comb.C(7, 3));
    EXPECT_EQ(35ULL, comb.C(7, 4));
    EXPECT_EQ(21ULL, comb.C(7, 5));
    EXPECT_EQ( 7ULL, comb.C(7, 6));
    EXPECT_EQ( 1ULL, comb.C(7, 7));

    EXPECT_EQ(     1ULL, comb.C(20, 0));
    EXPECT_EQ(    20ULL, comb.C(20, 1));
    EXPECT_EQ(   190ULL, comb.C(20, 2));
    EXPECT_EQ(  1140ULL, comb.C(20, 3));
    EXPECT_EQ(  4845ULL, comb.C(20, 4));
    EXPECT_EQ( 15504ULL, comb.C(20, 5));
    EXPECT_EQ( 38760ULL, comb.C(20, 6));
    EXPECT_EQ( 77520ULL, comb.C(20, 7));
    EXPECT_EQ(125970ULL, comb.C(20, 8));
    EXPECT_EQ(167960ULL, comb.C(20, 9));
    EXPECT_EQ(184756ULL, comb.C(20, 10));
    EXPECT_EQ(167960ULL, comb.C(20, 11));
    EXPECT_EQ(125970ULL, comb.C(20, 12));
    EXPECT_EQ( 77520ULL, comb.C(20, 13));
    EXPECT_EQ( 38760ULL, comb.C(20, 14));
    EXPECT_EQ( 15504ULL, comb.C(20, 15));
    EXPECT_EQ(  4845ULL, comb.C(20, 16));
    EXPECT_EQ(  1140ULL, comb.C(20, 17));
    EXPECT_EQ(   190ULL, comb.C(20, 18));
    EXPECT_EQ(    20ULL, comb.C(20, 19));
    EXPECT_EQ(     1ULL, comb.C(20, 20));

    EXPECT_THROW({
        // n > N
        comb.C(21, 0);
    }, std::out_of_range);

    EXPECT_THROW({
        // k > n
        comb.C(6, 7);
    }, std::out_of_range);

}


TEST(CombinationPascalTest, CombinationWithRepetition) {
    CombinationPascal<> comb(10);

    EXPECT_EQ(1ULL, comb.H(0, 0));

    EXPECT_EQ(1ULL, comb.H(1, 0));
    EXPECT_EQ(1ULL, comb.H(1, 1));
    EXPECT_EQ(1ULL, comb.H(1, 2));
    EXPECT_EQ(1ULL, comb.H(1, 3));

    EXPECT_EQ(1ULL, comb.H(2, 0));
    EXPECT_EQ(2ULL, comb.H(2, 1));
    EXPECT_EQ(3ULL, comb.H(2, 2));
    EXPECT_EQ(4ULL, comb.H(2, 3));
    EXPECT_EQ(5ULL, comb.H(2, 4));

    EXPECT_EQ( 1ULL, comb.H(3, 0));
    EXPECT_EQ( 3ULL, comb.H(3, 1));
    EXPECT_EQ( 6ULL, comb.H(3, 2));
    EXPECT_EQ(10ULL, comb.H(3, 3));
    EXPECT_EQ(15ULL, comb.H(3, 4));
    EXPECT_EQ(21ULL, comb.H(3, 5));

    EXPECT_NO_THROW({
        // n + k - 1 == N
        comb.H(11, 0);
    });

    EXPECT_THROW({
        // n + k - 1 > N
        comb.H(12, 0);
    }, std::out_of_range);

    EXPECT_NO_THROW({
        // n + k - 1 == N
        comb.H(3, 8);
    });

    EXPECT_THROW({
        // n + k - 1 > N
        comb.H(3, 9);
    }, std::out_of_range);

}
