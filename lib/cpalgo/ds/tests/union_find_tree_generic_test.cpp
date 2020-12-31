#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/ds/union_find_tree_generic.hpp"


class UnionFindTreeGenericTest : public ::testing::Test {
public:
    struct Data {
        size_t size;
        long long weight;
        Data(size_t i): size(1), weight(0) {}
        static void compress(Data& node, const Data& leader) {
            node.weight += leader.weight;
            node.size = leader.size;
        }
        static void unite_same(Data& leader, const Data& u, const Data& v, int const& w) {
            // Do nothing
        }
        static void unite_diff(Data& leader, Data& follower, const Data& a, const Data& b, int w) {
            w -= a.weight;
            w += b.weight;
            follower.weight = -w;
            size_t new_size = leader.size + follower.size;
            leader.size = follower.size = new_size;
        }
    };
};


TEST(UnionFindTreeGenericTest, ShouldHandleEmpty) {
    UnionFindTree<UnionFindTreeGenericTest::Data,int> tree;
    EXPECT_EQ(0ULL, tree.size());
}

TEST(UnionFindTreeGenericTest, ShouldReturnSize) {
    UnionFindTree<UnionFindTreeGenericTest::Data,int> tree(5);
    EXPECT_EQ(5ULL, tree.size());
}

TEST(UnionFindTreeGenericTest, ShouldHandleUniteAndSame) {
    const size_t N = 8;
    UnionFindTree<UnionFindTreeGenericTest::Data,int> tree(N);

    {
        EXPECT_FALSE(tree.same(0, 1));
        EXPECT_TRUE(tree.unite(0, 1, 2));
        EXPECT_FALSE(tree.unite(0, 1, 10000));
        EXPECT_TRUE(tree.same(0, 1));

        EXPECT_EQ(2, tree.find(0).value.weight - tree.find(1).value.weight);
        EXPECT_EQ(2ULL, tree.find(0).value.size);
        EXPECT_EQ(2ULL, tree.find(1).value.size);
    }

    {
        EXPECT_FALSE(tree.same(1, 2));
        EXPECT_TRUE(tree.unite(1, 2, -3));
        EXPECT_FALSE(tree.unite(1, 2, 100));
        EXPECT_TRUE(tree.same(1, 2));
        EXPECT_TRUE(tree.same(1, 0));

        EXPECT_EQ(-3, tree.find(1).value.weight - tree.find(2).value.weight);
        EXPECT_EQ(-1, tree.find(0).value.weight - tree.find(2).value.weight);

        EXPECT_EQ(3ULL, tree.find(0).value.size);
        EXPECT_EQ(3ULL, tree.find(1).value.size);
        EXPECT_EQ(3ULL, tree.find(2).value.size);
    }

}