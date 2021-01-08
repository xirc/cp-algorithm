#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/tree/lowest-common-ancestor/lca-binary-lifting.hpp"

using namespace std;


TEST(LCABinaryLiftingTest, IsEmptyInitially) {
    LCA solver;
    EXPECT_EQ(0ULL, solver.size());
}

TEST(LCABinaryLiftingTest, CanBuildLater) {
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

TEST(LCABinaryLiftingTest, ShouldComputeLCA) {
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

TEST(LCABinaryLiftingTest, ShouldComputeAncestor) {
    vector<vector<size_t>> G(8);
    G[0] = { 1, 2, 3 };
    G[1] = { 4, 5 };
    G[5] = { 6, 7 };

    LCA solver(G);

    EXPECT_TRUE(solver.is_ancestor(5, 6));
    EXPECT_FALSE(solver.is_ancestor(6, 5));
    EXPECT_FALSE(solver.is_ancestor(4, 6));
    EXPECT_FALSE(solver.is_ancestor(6, 4));
    EXPECT_TRUE(solver.is_ancestor(1, 7));
    EXPECT_FALSE(solver.is_ancestor(7, 1));
}

TEST(LCABinaryLiftingTest, ShouldComputeUpperBound) {
    vector<vector<size_t>> G(8);
    G[0] = { 1, 2, 3 };
    G[1] = { 4, 5 };
    G[5] = { 6, 7 };

    LCA solver(G);

    EXPECT_EQ(5ULL, solver.upper_bound(7, 1));
    EXPECT_EQ(5ULL, solver.upper_bound(5, 1));
    EXPECT_EQ(1ULL, solver.upper_bound(5, 0));
    EXPECT_EQ(1ULL, solver.upper_bound(4, 2));
    EXPECT_EQ(1ULL, solver.upper_bound(6, 2));

    EXPECT_EQ(8ULL, solver.upper_bound(1, 7));
    EXPECT_EQ(8ULL, solver.upper_bound(1, 5));
    EXPECT_EQ(8ULL, solver.upper_bound(0, 5));
}


TEST(LCABinaryLiftingTest, ShouldComputeEulerTour) {
    vector<vector<size_t>> G(6);
    G[0] = { 1, 2, 3 };
    G[1] = { 4, 5 };

    LCA solver(G);

    EXPECT_EQ(0ULL, solver.euler_in(0));
    EXPECT_EQ(1ULL, solver.euler_in(1));
    EXPECT_EQ(7ULL, solver.euler_in(2));
    EXPECT_EQ(9ULL, solver.euler_in(3));
    EXPECT_EQ(2ULL, solver.euler_in(4));
    EXPECT_EQ(4ULL, solver.euler_in(5));

    EXPECT_EQ(11ULL, solver.euler_out(0));
    EXPECT_EQ(6ULL, solver.euler_out(1));
    EXPECT_EQ(8ULL, solver.euler_out(2));
    EXPECT_EQ(10ULL, solver.euler_out(3));
    EXPECT_EQ(3ULL, solver.euler_out(4));
    EXPECT_EQ(5ULL, solver.euler_out(5));
}