#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/graph/articulation_points.hpp"

using namespace std;


TEST(ArticulationPointsTest, IsEmptyInitially) {
    ArticulationPoints solver;
    EXPECT_EQ(0ULL, solver.size());
}

TEST(ArticulationPointsTest, ShouldComputeArticulationPointsInCase1) {
    size_t const N = 4;
    ArticulationPoints solver(N);

    // articulation_points_testcase1
    solver.add_edge(0, 1);
    solver.add_edge(0, 2);
    solver.add_edge(1, 2);
    solver.add_edge(2, 3);

    auto aps = solver.solve();
    EXPECT_EQ(aps, vector<size_t>({ 2ULL }));
}

TEST(ArticulationPointsTest, ShouldComputeArticulationPointsInCase2) {
    size_t const N = 5;
    ArticulationPoints solver(N);

    // articulation_points_testcase2
    solver.add_edge(0, 1);
    solver.add_edge(1, 2);
    solver.add_edge(2, 3);
    solver.add_edge(3, 4);

    auto aps = solver.solve();
    sort(aps.begin(), aps.end());
    EXPECT_EQ(aps, vector<size_t>({ 1ULL, 2ULL, 3ULL }));
}

TEST(ArticulationPointsTest, ShouldComputeArticulationPointsInCase3) {
    size_t const N = 5;
    ArticulationPoints solver(N);

    // articulation_points_testcase3
    solver.add_edge(0, 1);
    solver.add_edge(0, 2);
    solver.add_edge(0, 2);
    solver.add_edge(1, 2);
    solver.add_edge(2, 3);
    solver.add_edge(2, 3);

    auto aps = solver.solve();
    sort(aps.begin(), aps.end());
    EXPECT_EQ(aps, vector<size_t>({ 2ULL }));
}
