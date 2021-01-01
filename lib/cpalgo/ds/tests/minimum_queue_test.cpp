#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/ds/minimum_queue.hpp"


TEST(MinimumQueueTest, IsEmptyInitially) {
    MinimumQueue<int> q;
    EXPECT_TRUE(q.empty());
    EXPECT_EQ(0ULL, q.size());
}

TEST(MinimumQueueTest, ShouldPushItems) {
    MinimumQueue<int> q;

    q.push(2);
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(1ULL, q.size());
    EXPECT_EQ(2, q.minimum());
    EXPECT_EQ(2, q.front());
    EXPECT_EQ(2, q.back());

    q.push(1);
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(2ULL, q.size());
    EXPECT_EQ(1, q.minimum());
    EXPECT_EQ(2, q.front());
    EXPECT_EQ(1, q.back());

    q.push(3);
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(3ULL, q.size());
    EXPECT_EQ(1, q.minimum());
    EXPECT_EQ(2, q.front());
    EXPECT_EQ(3, q.back());
}

TEST(MinimumQueueTest, ShouldPopItems) {
    MinimumQueue<int> q;

    q.push(2);
    q.push(1);
    q.push(3);
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(3ULL, q.size());
    EXPECT_EQ(1, q.minimum());
    EXPECT_EQ(2, q.front());
    EXPECT_EQ(3, q.back());

    q.pop();
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(2ULL, q.size());
    EXPECT_EQ(1, q.minimum());
    EXPECT_EQ(1, q.front());
    EXPECT_EQ(3, q.back());

    q.pop();
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(1ULL, q.size());
    EXPECT_EQ(3, q.minimum());
    EXPECT_EQ(3, q.front());
    EXPECT_EQ(3, q.back());

    q.pop();
    EXPECT_TRUE(q.empty());
    EXPECT_EQ(0ULL, q.size());
}

TEST(MinimumQueueTest, ShouldPushAndPopItems) {
    MinimumQueue<int> q;

    q.push(2);
    q.pop();
    q.push(1);
    q.push(3);

    EXPECT_FALSE(q.empty());
    EXPECT_EQ(2ULL, q.size());
    EXPECT_EQ(1, q.minimum());
    EXPECT_EQ(1, q.front());
    EXPECT_EQ(3, q.back());

    q.pop();
    q.push(0);
    q.push(4);

    EXPECT_FALSE(q.empty());
    EXPECT_EQ(3ULL, q.size());
    EXPECT_EQ(0, q.minimum());
    EXPECT_EQ(3, q.front());
    EXPECT_EQ(4, q.back());
}

TEST(MinimumQueueTest, ShouldUseCustomComparator) {
    MinimumQueue<int, std::greater<int>> q;

    q.push(2);
    EXPECT_EQ(2, q.minimum());
    EXPECT_EQ(2, q.front());
    EXPECT_EQ(2, q.back());

    q.push(3);
    EXPECT_EQ(3, q.minimum());
    EXPECT_EQ(2, q.front());
    EXPECT_EQ(3, q.back());

    q.push(1);
    EXPECT_EQ(3, q.minimum());
    EXPECT_EQ(2, q.front());
    EXPECT_EQ(1, q.back());
}
