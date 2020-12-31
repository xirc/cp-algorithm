#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/ds/union_find_tree_group.hpp"


TEST(UnionFindTreeGroupTest, ShouldHandleEmpty) {
    UnionFindTree<int> tree;
    EXPECT_EQ(0ULL, tree.size());
}

TEST(UnionFindTreeGroupTest, ShouldReturnSize) {
    UnionFindTree<int> tree(5);
    EXPECT_EQ(5ULL, tree.size());
}

TEST(UnionFindTreeGroupTest, ShouldHandleUniteAndSame) {
    const size_t N = 8;
    UnionFindTree<int> tree(N);

    {
        EXPECT_FALSE(tree.same(0, 1));
        EXPECT_TRUE(tree.unite(0, 1, 2));
        EXPECT_FALSE(tree.unite(0, 1, 10000));
        EXPECT_TRUE(tree.same(0, 1));
        int w;
        EXPECT_TRUE(tree.diff(0, 1, w));
        EXPECT_EQ(2, w);
        EXPECT_TRUE(tree.diff(1, 0, w));
        EXPECT_EQ(-2, w);
    }

    {
        EXPECT_FALSE(tree.same(1, 2));
        EXPECT_TRUE(tree.unite(1, 2, -3));
        EXPECT_FALSE(tree.unite(1, 2, 100));
        EXPECT_TRUE(tree.same(1, 2));
        EXPECT_TRUE(tree.same(1, 0));
        int w;
        EXPECT_TRUE(tree.diff(1, 2, w));
        EXPECT_EQ(-3, w);
        EXPECT_TRUE(tree.diff(2, 1, w));
        EXPECT_EQ(3, w);
        EXPECT_TRUE(tree.diff(0, 2, w));
        EXPECT_EQ(-1, w);
        EXPECT_TRUE(tree.diff(2, 0, w));
        EXPECT_EQ(1, w);
    }

}