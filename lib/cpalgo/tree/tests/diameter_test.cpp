#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/tree/diameter.hpp"

using namespace std;


TEST(DiameterTest, IsEmptyInitially) {
    TreeDiameter solver;
    EXPECT_EQ(0ULL, solver.size());
}

TEST(DiameterTest, ShouldComputeDiameterOfATree) {
    TreeDiameter solver(6);
    solver.add_edge(0, 1, 1);
    solver.add_edge(0, 2, 1);
    solver.add_edge(2, 3, 4);
    solver.add_edge(2, 5, 2);
    solver.add_edge(5, 4, 1);
    size_t u, v;
    unsigned long long w;
    tie(u, v, w) = solver.solve();
    EXPECT_EQ(3ULL, u);
    EXPECT_EQ(4ULL, v);
    EXPECT_EQ(7ULL, w);
}

TEST(DiameterTest, ShouldComputeDiameterOfTrees) {
    TreeDiameter solver(10);
    // tree A
    solver.add_edge(0, 1, 1);
    solver.add_edge(0, 2, 1);
    solver.add_edge(2, 3, 1);

    // tree B
    solver.add_edge(4, 5, 1);
    solver.add_edge(4, 6, 1);
    solver.add_edge(5, 7, 1);
    solver.add_edge(5, 8, 1);
    solver.add_edge(9, 8, 1);

    size_t u, v;
    unsigned long long w;

    tie(u, v, w) = solver.solve(1);
    EXPECT_EQ(1ULL, u);
    EXPECT_EQ(3ULL, v);
    EXPECT_EQ(3ULL, w);

    tie(u, v, w) = solver.solve(5);
    EXPECT_EQ(6ULL, u);
    EXPECT_EQ(9ULL, v);
    EXPECT_EQ(4ULL, w);
}
