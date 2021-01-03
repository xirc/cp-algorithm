#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/graph/bellman-ford.hpp"

using namespace std;


TEST(BellmanFordTest, IsEmptyInitially) {
    BellmanFord solver;
    EXPECT_EQ(0ULL, solver.size());
}

TEST(BellmanFordTest, ShouldComputeAllDistancesOnConnectedGraph) {
    size_t N = 4;
    BellmanFord solver(N);

    solver.add_edge(0, 1, 2);
    solver.add_edge(0, 2, 3);
    solver.add_edge(1, 2, -5);
    solver.add_edge(1, 3, 1);
    solver.add_edge(2, 3, 2);

    vector<long long> D;
    vector<size_t> P;
    auto no_cycle = solver.solve(0, D, P);

    EXPECT_TRUE(no_cycle);
    EXPECT_EQ(N, D.size());
    EXPECT_EQ(0LL, D[0]);
    EXPECT_EQ(2LL, D[1]);
    EXPECT_EQ(-3LL, D[2]);
    EXPECT_EQ(-1LL, D[3]);

    EXPECT_EQ(N, P.size());
    EXPECT_EQ(N, P[0]);
    EXPECT_EQ(0ULL, P[1]);
    EXPECT_EQ(1ULL, P[2]);
    EXPECT_EQ(2ULL, P[3]);
}

TEST(BellmanFordTest, ShouldFindNegativeCycle) {
    size_t N = 4;
    BellmanFord solver(N);
    
    solver.add_edge(0, 1, 2);
    solver.add_edge(0, 2, 3);
    solver.add_edge(1, 2, -5);
    solver.add_edge(1, 3, 1);
    solver.add_edge(2, 3, 2);
    solver.add_edge(3, 1, 0);

    vector<long long> D;
    vector<size_t> P;
    auto no_cycle = solver.solve(0, D, P);

    EXPECT_FALSE(no_cycle);

    EXPECT_EQ(N, D.size());
    EXPECT_EQ(N, P.size());
    EXPECT_EQ(N, P[0]);
    EXPECT_EQ(3ULL, P[1]);
    EXPECT_EQ(1ULL, P[2]);
    EXPECT_EQ(2ULL, P[3]);
}

TEST(BellmanFordTest, ShouldComputeAllDistancesOnDisconnectedGraph) {
    size_t N = 4;
    BellmanFord solver(N);
    
    solver.add_edge(0, 1, 2);
    solver.add_edge(0, 2, 3);
    solver.add_edge(1, 2, -5);
    solver.add_edge(1, 3, 1);
    solver.add_edge(2, 3, 2);

    vector<long long> D;
    vector<size_t> P;
    auto no_cycle = solver.solve(1, D, P);

    EXPECT_TRUE(no_cycle);
    EXPECT_EQ(N, D.size());
    EXPECT_EQ(solver.infinity(), D[0]);
    EXPECT_EQ(0LL, D[1]);
    EXPECT_EQ(-5LL, D[2]);
    EXPECT_EQ(-3LL, D[3]);

    EXPECT_EQ(N, P.size());
    EXPECT_EQ(N, P[0]);
    EXPECT_EQ(N, P[1]);
    EXPECT_EQ(1ULL, P[2]);
    EXPECT_EQ(2ULL, P[3]);
}
