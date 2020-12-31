#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/ds/union_find_tree.hpp"


TEST(UnionFindTreeTest, ShouldHandleEmpty) {
    UnionFindTree tree;
    EXPECT_EQ(0ULL, tree.size());
}

TEST(UnionFindTreeTest, ShouldReturnSize) {
    auto tree = UnionFindTree(5);
    EXPECT_EQ(5ULL, tree.size());
}

TEST(UnionFindTreeTest, ShouldHandleUniteAndSame) {
    const size_t N = 10;
    auto tree = UnionFindTree(N);

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            if (i == j) {
                EXPECT_TRUE(tree.same(i, j));
            } else {
                EXPECT_FALSE(tree.same(i, j));
            }
        }
    }

    EXPECT_TRUE(tree.unite(0, 3));
    EXPECT_TRUE(tree.same(3, 0));
    EXPECT_TRUE(tree.same(0, 3));
    EXPECT_FALSE(tree.unite(0, 3));

    EXPECT_TRUE(tree.unite(1, 4));
    EXPECT_TRUE(tree.same(1, 4));
    EXPECT_TRUE(tree.same(4, 1));
    EXPECT_FALSE(tree.unite(1, 4));

    EXPECT_TRUE(tree.unite(8, 6));
    EXPECT_TRUE(tree.same(6, 8));
    EXPECT_TRUE(tree.same(8, 6));
    EXPECT_FALSE(tree.unite(8, 6));

    EXPECT_FALSE(tree.same(0, 1));
    EXPECT_FALSE(tree.same(3, 1));
    EXPECT_FALSE(tree.same(1, 8));
    EXPECT_FALSE(tree.same(4, 6));
    EXPECT_FALSE(tree.same(3, 8));

    EXPECT_TRUE(tree.unite(3, 1));
    EXPECT_TRUE(tree.same(0, 3));
    EXPECT_TRUE(tree.same(0, 1));
    EXPECT_TRUE(tree.same(0, 4));
    EXPECT_TRUE(tree.same(3, 1));
    EXPECT_TRUE(tree.same(3, 4));
    EXPECT_FALSE(tree.unite(3, 1));
}