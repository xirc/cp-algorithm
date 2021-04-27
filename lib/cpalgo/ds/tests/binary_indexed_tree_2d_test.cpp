#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/ds/binary_indexed_tree_2d.hpp"


TEST(BinaryIndexedTree2DTest, ShouldHandleEmpty) {
    BinaryIndexedTree2D<int> tree;
    auto expected_size = std::make_pair(size_t(0), size_t(0));
    EXPECT_EQ(expected_size, tree.size());
}

TEST(BinaryIndexedTree2DTest, ShouldReturnSize) {
    auto tree = BinaryIndexedTree2D<int>(5, 10);
    auto expected_size = std::make_pair(size_t(5), size_t(10));
    EXPECT_EQ(expected_size, tree.size());
}

TEST(BinaryIndexedTree2DTest, ShouldCombineAndFold) {
    const size_t N = 30, M = 20;
    auto tree = BinaryIndexedTree2D<int>(N, M);

    for (size_t x = 0; x < N; ++x) {
        for (size_t y = 0; y < M; ++y) {
            tree.combine(x, y, x+1);
        }
    }

    for (size_t x = 0; x <= N; ++x) {
        for (size_t y = 0; y <= M; ++y) {
            int expected_sum = x * (x + 1) / 2 * y;
            EXPECT_EQ(expected_sum, tree.fold(x, y));
        }
    }


    for (size_t xl = 0; xl <= N; ++xl) {
        for (size_t xr = xl; xr <= N; ++xr) {
            for (size_t yl = 0; yl <= M; ++yl) {
                for (size_t yr = yl; yr <= M; ++yr) {
                    int expected_sum =
                        xr * (xr + 1) / 2 * yr
                        - xr * (xr + 1) / 2 * yl
                        - xl * (xl + 1) / 2 * yr
                        + xl * (xl + 1) / 2 * yl;
                    EXPECT_EQ(expected_sum, tree.fold(xl, xr, yl, yr));
                }
            }
        }
    }

}