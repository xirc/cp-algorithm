#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/graph/bipartite/bipartite_check.hpp"

using namespace std;


TEST(BipartiteCheckTest, IsEmptyInitially) {

    BipartiteCheck solver;
    EXPECT_EQ(0ULL, solver.size());

}

TEST(BipartiteCheckTest, ShouldPassBipartite) {

    size_t const N = 6;
    BipartiteCheck solver(N);

    // bipartite_check_testcase1
    solver.add_edge(0, 1);
    solver.add_edge(0, 5);
    solver.add_edge(2, 1);
    solver.add_edge(2, 3);
    solver.add_edge(2, 5);

    EXPECT_TRUE(solver.solve());

}

TEST(BipartiteCheckTest, ShouldRejectNonBipartite) {

    size_t const N = 6;
    BipartiteCheck solver(N);

    // bipartite_check_testcase3
    solver.add_edge(0, 1);
    solver.add_edge(0, 5);
    solver.add_edge(1, 3);
    solver.add_edge(2, 1);
    solver.add_edge(2, 3);
    solver.add_edge(2, 5);

    EXPECT_FALSE(solver.solve());

}
