#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/tree/lowest-common-ancestor/lca-farach-colton-bender.hpp"

using namespace std;


TEST(LCAFarachColtonBenderTest, IsEmptyInitially) {
    LCA solver;
    EXPECT_EQ(0ULL, solver.size());
}

TEST(LCAFarachColtonBenderTest, CanBuildLater) {
    LCA solver;
    EXPECT_EQ(0ULL, solver.size());

    vector<vector<size_t>> G(4);
    G[0] = { 1, 2 };
    G[1] = { 3 };

    solver.build(G);

    EXPECT_EQ(4ULL, solver.size());
    EXPECT_EQ(0ULL, solver.query(1, 2));
    EXPECT_EQ(0ULL, solver.query(3, 2));
    EXPECT_EQ(1ULL, solver.query(3, 1));
}

TEST(LCAFarachColtonBenderTest, ShouldComputeLCA) {
    vector<vector<size_t>> G(8);
    G[0] = { 1, 2, 3 };
    G[1] = { 4, 5 };
    G[5] = { 6, 7 };

    LCA solver(G);
    EXPECT_EQ(8ULL, solver.size());

    EXPECT_EQ(1ULL, solver.query(4, 6));
    EXPECT_EQ(1ULL, solver.query(4, 7));
    EXPECT_EQ(0ULL, solver.query(4, 3));
    EXPECT_EQ(0ULL, solver.query(5, 2));
    EXPECT_EQ(5ULL, solver.query(6, 7));
}
