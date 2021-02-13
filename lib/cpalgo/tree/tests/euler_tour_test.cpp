#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/tree/euler_tour.hpp"

using namespace std;


TEST(EulerTourTest, IsEmptyInitially) {
    EulerTour solver;
    EXPECT_EQ(0ULL, solver.size());
}

TEST(EulerTourTest, ShouldComputeEulerTour) {
    EulerTour solver(7);
    EXPECT_EQ(7ULL, solver.size());

    // euler_tour_test_case1
    solver.add_edge(0, 1);
    solver.add_edge(1, 2);
    solver.add_edge(1, 3);
    solver.add_edge(0, 4);
    solver.add_edge(0, 5);
    solver.add_edge(5, 6);

    vector<size_t> tour, tin, tout;
    solver.solve(0, tour, tin, tout);

    vector<size_t> expected_tour = { 0, 1, 2, 2, 3, 3, 1, 4, 4, 5, 6, 6, 5, 0 };
    vector<size_t> expected_tin = { 0, 1, 2, 4, 7, 9, 10 };
    vector<size_t> expected_tout = { 13, 6, 3, 5, 8, 12, 11 };
    EXPECT_EQ(expected_tour, tour);
    EXPECT_EQ(expected_tin, tin);
    EXPECT_EQ(expected_tout, tout);
}

TEST(EulerTourTest, ShouldHandleAForest) {
    EulerTour solver(7);
    EXPECT_EQ(7ULL, solver.size());

    // euler_tour_test_case2
    solver.add_edge(0, 1);
    solver.add_edge(1, 2);
    solver.add_edge(1, 3);
    solver.add_edge(5, 6);

    vector<size_t> tour, tin, tout;
    solver.solve(0, tour, tin, tout);

    vector<size_t> expected_tour = { 0, 1, 2, 2, 3, 3, 1, 0 };
    vector<size_t> expected_tin = { 0, 1, 2, 4, 14, 14, 14 };
    vector<size_t> expected_tout = { 7, 6, 3, 5, 14, 14, 14 };
    EXPECT_EQ(expected_tour, tour);
    EXPECT_EQ(expected_tin, tin);
    EXPECT_EQ(expected_tout, tout);
}