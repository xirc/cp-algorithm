#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/util/modint.hpp"

using namespace std;


TEST(modint, init) {

    int const MOD = 7;
    for (int i = 0; i < 100; ++i) {
        auto v = modint<MOD>(i);
        EXPECT_EQ(uint64_t(i % MOD), v.value());
    }

}

TEST(modint, eq) {

    int const MOD = 7;
    EXPECT_EQ(modint<MOD>(0), modint<MOD>(0));
    EXPECT_EQ(modint<MOD>(1), modint<MOD>(1));
    EXPECT_EQ(modint<MOD>(2), modint<MOD>(2));
    EXPECT_EQ(modint<MOD>(3), modint<MOD>(3));
    EXPECT_EQ(modint<MOD>(4), modint<MOD>(4));
    EXPECT_EQ(modint<MOD>(5), modint<MOD>(5));
    EXPECT_EQ(modint<MOD>(6), modint<MOD>(6));
    EXPECT_EQ(modint<MOD>(7), modint<MOD>(0));
    EXPECT_EQ(modint<MOD>(8), modint<MOD>(1));

}

TEST(modint, neq) {

    int const MOD = 7;
    EXPECT_NE(modint<MOD>(0), modint<MOD>(1));
    EXPECT_NE(modint<MOD>(0), modint<MOD>(2));
    EXPECT_NE(modint<MOD>(0), modint<MOD>(3));
    EXPECT_NE(modint<MOD>(0), modint<MOD>(4));
    EXPECT_NE(modint<MOD>(0), modint<MOD>(5));
    EXPECT_NE(modint<MOD>(0), modint<MOD>(6));

}

TEST(modint, plus) {

    int const MOD = 7;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            auto v = modint<MOD>(i);
            auto u = v + j;
            uint64_t expected = (i + j) % MOD;
            EXPECT_EQ(expected, u.value());
        }
    }

}

TEST(modint, minus) {

    int const MOD = 7;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            auto v = modint<MOD>(i);
            auto u = v - j;
            uint64_t expected = ((i - j) % MOD + MOD) % MOD;
            EXPECT_EQ(expected, u.value());
        }
    }

}

TEST(modint, mult) {

    int const MOD = 7;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            auto v = modint<MOD>(i);
            auto u = v * j;
            uint64_t expected = (i * j) % MOD;
            EXPECT_EQ(expected, u.value());
        }
    }

}

TEST(modint, div) {

    int const MOD = 7;

    for (int i = 0; i < 7; ++i) {
        uint64_t expected = 0;
        auto u = modint<MOD>(0) / i;
        EXPECT_EQ(expected, u.value());
    }

    EXPECT_EQ(modint<MOD>(1), modint<MOD>(1) / modint<MOD>(1));
    EXPECT_EQ(modint<MOD>(4), modint<MOD>(1) / modint<MOD>(2));
    EXPECT_EQ(modint<MOD>(5), modint<MOD>(1) / modint<MOD>(3));
    EXPECT_EQ(modint<MOD>(2), modint<MOD>(1) / modint<MOD>(4));
    EXPECT_EQ(modint<MOD>(3), modint<MOD>(1) / modint<MOD>(5));
    EXPECT_EQ(modint<MOD>(6), modint<MOD>(1) / modint<MOD>(6));

    EXPECT_EQ(modint<MOD>(2), modint<MOD>(2) / modint<MOD>(1));
    EXPECT_EQ(modint<MOD>(1), modint<MOD>(2) / modint<MOD>(2));
    EXPECT_EQ(modint<MOD>(3), modint<MOD>(2) / modint<MOD>(3));
    EXPECT_EQ(modint<MOD>(4), modint<MOD>(2) / modint<MOD>(4));
    EXPECT_EQ(modint<MOD>(6), modint<MOD>(2) / modint<MOD>(5));
    EXPECT_EQ(modint<MOD>(5), modint<MOD>(2) / modint<MOD>(6));

}

TEST(modint, inv) {

    int const MOD = 7;
    EXPECT_EQ(modint<MOD>(1), ~modint<MOD>(1));
    EXPECT_EQ(modint<MOD>(4), ~modint<MOD>(2));
    EXPECT_EQ(modint<MOD>(5), ~modint<MOD>(3));
    EXPECT_EQ(modint<MOD>(2), ~modint<MOD>(4));
    EXPECT_EQ(modint<MOD>(3), ~modint<MOD>(5));
    EXPECT_EQ(modint<MOD>(6), ~modint<MOD>(6));

}

TEST(modint, ostream) {

    int const MOD = 7;
    for (int i = 0; i < 6; ++i) {
        std::stringstream ss;
        ss << modint<MOD>(i);
        EXPECT_EQ(to_string(i), ss.str());
    }

}