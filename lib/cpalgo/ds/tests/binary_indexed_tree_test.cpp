#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/ds/binary_indexed_tree.hpp"


TEST(BinaryIndexedTreeTest, ShouldHandleEmpty) {
    BinaryIndexedTree<int> tree;
    EXPECT_EQ(0ULL, tree.size());
}

TEST(BinaryIndexedTreeTest, ShouldReturnSize) {
    auto tree = BinaryIndexedTree<int>(5);
    EXPECT_EQ(5ULL, tree.size());
}

TEST(BinaryIndexedTreeTest, ShouldCombineAndFold) {
    const size_t N = 1000;
    auto tree = BinaryIndexedTree<int64_t>(N);

    for (size_t i = 0; i < N; ++i) {
        tree.combine(i, i+1);
    }

    for (size_t i = 0; i <= N; ++i) {
        int64_t expected_sum = i * (i + 1) / 2;
        EXPECT_EQ(expected_sum, tree.fold(i));
    }

    for (size_t l = 0; l <= N; ++l) {
        for (size_t r = l; r <= N; ++r) {
            int64_t lsum = l * (l + 1) / 2;
            int64_t rsum = r * (r + 1) / 2;
            auto expected_sum = rsum - lsum;
            EXPECT_EQ(expected_sum, tree.fold(l,r));
        }
    }

}