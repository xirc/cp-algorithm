#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/ds/minimum_stack.hpp"


TEST(MinimumStackTest, IsEmptyInitially) {
    MinimumStack<int> s;
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(0ULL, s.size());
}

TEST(MinimumStackTest, ShouldPushItems) {
    MinimumStack<int> s;

    s.push(2);
    EXPECT_FALSE(s.empty());
    EXPECT_EQ(1ULL, s.size());
    EXPECT_EQ(2, s.minimum());
    EXPECT_EQ(2, s.maximum());
    EXPECT_EQ(2, s.bottom());
    EXPECT_EQ(2, s.top());

    s.push(1);
    EXPECT_FALSE(s.empty());
    EXPECT_EQ(2ULL, s.size());
    EXPECT_EQ(1, s.minimum());
    EXPECT_EQ(2, s.maximum());
    EXPECT_EQ(2, s.bottom());
    EXPECT_EQ(1, s.top());

    s.push(3);
    EXPECT_FALSE(s.empty());
    EXPECT_EQ(3ULL, s.size());
    EXPECT_EQ(1, s.minimum());
    EXPECT_EQ(3, s.maximum());
    EXPECT_EQ(2, s.bottom());
    EXPECT_EQ(3, s.top());
}

TEST(MinimumStackTest, ShouldPopItems) {
    MinimumStack<int> s;

    s.push(2);
    s.push(1);
    s.push(3);

    EXPECT_FALSE(s.empty());
    EXPECT_EQ(3ULL, s.size());
    EXPECT_EQ(1, s.minimum());
    EXPECT_EQ(3, s.maximum());
    EXPECT_EQ(2, s.bottom());
    EXPECT_EQ(3, s.top());

    s.pop();
    EXPECT_FALSE(s.empty());
    EXPECT_EQ(2ULL, s.size());
    EXPECT_EQ(1, s.minimum());
    EXPECT_EQ(2, s.maximum());
    EXPECT_EQ(2, s.bottom());
    EXPECT_EQ(1, s.top());

    s.pop();
    EXPECT_FALSE(s.empty());
    EXPECT_EQ(1ULL, s.size());
    EXPECT_EQ(2, s.minimum());
    EXPECT_EQ(2, s.maximum());
    EXPECT_EQ(2, s.bottom());
    EXPECT_EQ(2, s.top());

    s.pop();
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(0ULL, s.size());
}

TEST(MinimumStackTest, ShouldUseCustomComparator) {
    MinimumStack<int, std::greater<int>> s;

    s.push(2);
    EXPECT_EQ(2, s.minimum());
    EXPECT_EQ(2, s.maximum());
    EXPECT_EQ(2, s.bottom());
    EXPECT_EQ(2, s.top());

    s.push(3);
    EXPECT_EQ(3, s.minimum());
    EXPECT_EQ(2, s.maximum());
    EXPECT_EQ(2, s.bottom());
    EXPECT_EQ(3, s.top());

    s.push(1);
    EXPECT_EQ(3, s.minimum());
    EXPECT_EQ(1, s.maximum());
    EXPECT_EQ(2, s.bottom());
    EXPECT_EQ(1, s.top());
}
