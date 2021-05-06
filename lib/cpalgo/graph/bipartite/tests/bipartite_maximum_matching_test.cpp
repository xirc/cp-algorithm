#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/graph/bipartite/bipartite_maximum_matching.hpp"

using namespace std;


TEST(BipartiteMaximumMatchingTest, IsEmptyInitially) {

    BipartiteMaximumMatching solver;
    EXPECT_EQ(0ULL, solver.size());

}

TEST(BipartiteMaximumMatchingTest, ShouldComputeInCase1) {

    size_t const N = 7;
    BipartiteMaximumMatching solver(N);

    // bipartite_maximum_matching_testcase1
    solver.add_edge(0, 1);
    solver.add_edge(2, 1);
    solver.add_edge(2, 3);
    solver.add_edge(2, 5);
    solver.add_edge(4, 3);

    vector<size_t> match;
    auto num_match = solver.solve(match);
    EXPECT_EQ(num_match, size_t(3));
    EXPECT_EQ(match[0], size_t(1));
    EXPECT_EQ(match[1], size_t(0));
    EXPECT_EQ(match[2], size_t(5));
    EXPECT_EQ(match[3], size_t(4));
    EXPECT_EQ(match[4], size_t(3));
    EXPECT_EQ(match[5], size_t(2));
    EXPECT_EQ(match[6], size_t(7));

}