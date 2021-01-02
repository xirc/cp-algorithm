#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/tree/height.hpp"

using namespace std;


TEST(TreeHeightTest, IsEmptyInitially) {
    TreeHeight solver;
    EXPECT_EQ(0ULL, solver.size());
}

TEST(TreeHeightTest, ShouldComputeHeightOfTree) {
    TreeHeight solver(4);

    solver.add_edge(0, 1, 2);
    solver.add_edge(1, 2, 1);
    solver.add_edge(1, 3, 3);

    auto ds = solver.solve(0);
    EXPECT_EQ(5ULL, ds[0]);
    EXPECT_EQ(3ULL, ds[1]);
    EXPECT_EQ(4ULL, ds[2]);
    EXPECT_EQ(5ULL, ds[3]);
}

TEST(TreeHeightTest, ShouldComputeHeightOfTrees) {
    TreeHeight solver(8);

    solver.add_edge(0, 1, 2);
    solver.add_edge(1, 2, 1);
    solver.add_edge(1, 3, 3);

    solver.add_edge(4, 5, 1);
    solver.add_edge(5, 6, 2);
    solver.add_edge(6, 7, 1);

    auto ds = solver.solve(0);
    EXPECT_EQ(5ULL, ds[0]);
    EXPECT_EQ(3ULL, ds[1]);
    EXPECT_EQ(4ULL, ds[2]);
    EXPECT_EQ(5ULL, ds[3]);
    EXPECT_EQ(solver.infinity(), ds[4]);
    EXPECT_EQ(solver.infinity(), ds[5]);
    EXPECT_EQ(solver.infinity(), ds[6]);
    EXPECT_EQ(solver.infinity(), ds[7]);

    auto ds2 = solver.solve(7);
    EXPECT_EQ(solver.infinity(), ds2[0]);
    EXPECT_EQ(solver.infinity(), ds2[1]);
    EXPECT_EQ(solver.infinity(), ds2[2]);
    EXPECT_EQ(solver.infinity(), ds2[3]);
    EXPECT_EQ(4ULL, ds2[4]);
    EXPECT_EQ(3ULL, ds2[5]);
    EXPECT_EQ(3ULL, ds2[6]);
    EXPECT_EQ(4ULL, ds2[7]);
}
