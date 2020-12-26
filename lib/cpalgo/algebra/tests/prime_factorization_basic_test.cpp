#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/algebra/prime_factorization_basic.hpp"


TEST(PrimeFactorizationBasicTest, ShouldFactorize) {
    std::vector<unsigned long long> factors_0 = { };
    EXPECT_EQ(prime_factorization(0), factors_0);

    std::vector<unsigned long long> factors_1 = { };
    EXPECT_EQ(prime_factorization(1), factors_1);

    std::vector<unsigned long long> factors_2 = { 2 };
    EXPECT_EQ(prime_factorization(2), factors_2);

    std::vector<unsigned long long> factors_3 = { 3 };
    EXPECT_EQ(prime_factorization(3), factors_3);

    std::vector<unsigned long long> factors_4 = { 2, 2 };
    EXPECT_EQ(prime_factorization(4), factors_4);

    std::vector<unsigned long long> factors_9 = { 3, 3 };
    EXPECT_EQ(prime_factorization(9), factors_9);

    std::vector<unsigned long long> factors_12 = { 2, 2, 3 };
    EXPECT_EQ(prime_factorization(12), factors_12);

    std::vector<unsigned long long> factors_126 = { 2, 3, 3, 7 };
    EXPECT_EQ(prime_factorization(126), factors_126);

    std::vector<unsigned long long> factors_1331 = { 11, 11, 11 };
    EXPECT_EQ(prime_factorization(1331), factors_1331);
}