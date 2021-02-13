#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/tree/lca/lca_segment_tree.hpp"

using namespace std;


TEST(LCASegmentTreeTest, IsEmptyInitially) {
    LCASegmentTree solver;
    EXPECT_EQ(0ULL, solver.size());
}

TEST(LCASegmentTreeTest, CanBuildLater) {
    LCASegmentTree solver;
    EXPECT_EQ(0ULL, solver.size());

    // lca_test_case_1
    vector<vector<size_t>> G(4);
    G[0] = { 1, 2 };
    G[1] = { 0, 3 };
    G[2] = { 0 };
    G[3] = { 1 };

    solver.build(G);

    EXPECT_EQ(4ULL, solver.size());
    EXPECT_EQ(0ULL, solver.query(1, 2));
    EXPECT_EQ(0ULL, solver.query(3, 2));
    EXPECT_EQ(1ULL, solver.query(3, 1));
}

TEST(LCASegmentTreeTest, ShouldComputeLCA) {
    // lca_test_case2
    vector<vector<size_t>> G(9);
    G[0] = { 1, 2, 3 };
    G[1] = { 0, 4, 5 };
    G[2] = { 0 };
    G[3] = { 0, 8 };
    G[4] = { 1 };
    G[5] = { 1, 6, 7 };
    G[6] = { 5 };
    G[7] = { 5 };
    G[8] = { 3 };

    LCASegmentTree solver(G);
    EXPECT_EQ(9ULL, solver.size());

    EXPECT_EQ(1ULL, solver.query(4, 6));
    EXPECT_EQ(1ULL, solver.query(4, 7));
    EXPECT_EQ(0ULL, solver.query(4, 3));
    EXPECT_EQ(0ULL, solver.query(5, 2));
    EXPECT_EQ(5ULL, solver.query(6, 7));
    EXPECT_EQ(3ULL, solver.query(8, 3));
    EXPECT_EQ(0ULL, solver.query(8, 2));
}
