#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/algebra/prime_factorization_basic.hpp"


TEST(PrimeFactorizationBasicTest, ShouldFactorize) {
    std::vector<unsigned long long> factors_12 = { 2, 2, 3 };
    EXPECT_EQ(prime_factorization(12), factors_12);

    std::vector<unsigned long long> factors_126 = { 2, 3, 3, 7 };
    EXPECT_EQ(prime_factorization(126), factors_126);
}