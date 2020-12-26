#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/algebra/prime_factorization_basic.hpp"


TEST(PrimeFactorizationBasicTest, ShouldFactorize) {
    std::vector<unsigned long long> factors_0 = { };
    EXPECT_EQ(factors_0, prime_factorization(0));

    std::vector<unsigned long long> factors_1 = { };
    EXPECT_EQ(factors_1, prime_factorization(1));

    std::vector<unsigned long long> factors_2 = { 2 };
    EXPECT_EQ(factors_2, prime_factorization(2));

    std::vector<unsigned long long> factors_3 = { 3 };
    EXPECT_EQ(factors_3, prime_factorization(3));

    std::vector<unsigned long long> factors_4 = { 2, 2 };
    EXPECT_EQ(factors_4, prime_factorization(4));

    std::vector<unsigned long long> factors_9 = { 3, 3 };
    EXPECT_EQ(factors_9, prime_factorization(9));

    std::vector<unsigned long long> factors_12 = { 2, 2, 3 };
    EXPECT_EQ(factors_12, prime_factorization(12));

    std::vector<unsigned long long> factors_126 = { 2, 3, 3, 7 };
    EXPECT_EQ(factors_126, prime_factorization(126));

    std::vector<unsigned long long> factors_1331 = { 11, 11, 11 };
    EXPECT_EQ(factors_1331, prime_factorization(1331));
}