#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/util/quick_select.hpp"

using namespace std;

TEST(QuickSelectTest, ShouldSelectInSmallCases) {

    auto select = QuickSelect<int>();
    vector<int> n1 = { 1 };
    EXPECT_EQ( 1, select(n1, 0));

    vector<int> n12 = { 1, 2 };
    EXPECT_EQ( 1, select(n12, 0));
    EXPECT_EQ( 2, select(n12, 1));

    vector<int> n11 = { 1, 1 };
    EXPECT_EQ( 1, select(n11, 0));
    EXPECT_EQ( 1, select(n11, 1));

    vector<int> n112 = { 1, 1, 2 };
    EXPECT_EQ( 1, select(n112, 0));
    EXPECT_EQ( 1, select(n112, 1));
    EXPECT_EQ( 2, select(n112, 2));

}

TEST(QuickSelectTest, ShouldSelect) {

    auto select = QuickSelect<int>();
    vector<int> values = { 1, 3, 2, 6, 7, 4, 5, 10, 8, 9 };
    EXPECT_EQ( 1, select(values, 0));
    EXPECT_EQ( 2, select(values, 1));
    EXPECT_EQ( 3, select(values, 2));
    EXPECT_EQ( 4, select(values, 3));
    EXPECT_EQ( 5, select(values, 4));
    EXPECT_EQ( 6, select(values, 5));
    EXPECT_EQ( 7, select(values, 6));
    EXPECT_EQ( 8, select(values, 7));
    EXPECT_EQ( 9, select(values, 8));
    EXPECT_EQ(10, select(values, 9));

}

TEST(QuickSelectTest, ShouldSelectUsingCustomComparator) {

    auto select = QuickSelect<int, greater<int>>();
    vector<int> values = { 1, 3, 2, 6, 7, 4, 5, 10, 8, 9 };
    EXPECT_EQ(10, select(values, 0));
    EXPECT_EQ( 9, select(values, 1));
    EXPECT_EQ( 8, select(values, 2));
    EXPECT_EQ( 7, select(values, 3));
    EXPECT_EQ( 6, select(values, 4));
    EXPECT_EQ( 5, select(values, 5));
    EXPECT_EQ( 4, select(values, 6));
    EXPECT_EQ( 3, select(values, 7));
    EXPECT_EQ( 2, select(values, 8));
    EXPECT_EQ( 1, select(values, 9));

}

TEST(QuickSelectTest, ShouldSelectInRandomizedCase) {

    size_t const N = 1000;
    vector<int> values(N);
    random_device seed_generator;
    mt19937 random(seed_generator());
    for (auto &value : values) {
        value = abs((int)(random() % 100));
    }
    auto sorted_values = values;
    sort(sorted_values.begin(), sorted_values.end());

    auto select = QuickSelect<int>();
    for (size_t i = 0; i < N; ++i) {
        EXPECT_EQ(sorted_values[i], select(values, i));
    }

}
