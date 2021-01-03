#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/tree/lowest-common-ancestor/lca-tarjan.hpp"

using namespace std;


TEST(LCATarjanTest, ShouldComputeLCA) {
    vector<vector<size_t>> G(8);
    G[0] = { 1, 2, 3 };
    G[1] = { 4, 5 };
    G[5] = { 6, 7 };

    vector<pair<size_t,size_t>> Q;
    Q.push_back({ 4, 6 });
    Q.push_back({ 4, 7 });
    Q.push_back({ 4, 3 });
    Q.push_back({ 5, 2 });
    Q.push_back({ 6, 7 });

    auto result = lca(G, Q);
    EXPECT_EQ(1ULL, result[0]);
    EXPECT_EQ(1ULL, result[1]);
    EXPECT_EQ(0ULL, result[2]);
    EXPECT_EQ(0ULL, result[3]);
    EXPECT_EQ(5ULL, result[4]);
}

