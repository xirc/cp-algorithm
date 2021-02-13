#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/tree/lca/lca_tarjan.hpp"

using namespace std;


TEST(LCATarjanTest, ShouldComputeLCA) {
    // lca_test_case2
    vector<vector<size_t>> G(9);
    G[0] = { 1, 2, 3 };
    G[1] = { 4, 5 };
    G[3] = { 8 };
    G[5] = { 6, 7 };

    vector<pair<size_t,size_t>> Q;
    Q.push_back({ 4, 6 });
    Q.push_back({ 4, 7 });
    Q.push_back({ 4, 3 });
    Q.push_back({ 5, 2 });
    Q.push_back({ 6, 7 });
    Q.push_back({ 8, 3 });
    Q.push_back({ 8, 2 });

    auto result = lca(G, Q);
    EXPECT_EQ(1ULL, result[0]);
    EXPECT_EQ(1ULL, result[1]);
    EXPECT_EQ(0ULL, result[2]);
    EXPECT_EQ(0ULL, result[3]);
    EXPECT_EQ(5ULL, result[4]);
    EXPECT_EQ(3ULL, result[5]);
    EXPECT_EQ(0ULL, result[6]);
}

