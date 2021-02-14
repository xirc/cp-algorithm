#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/tree/heavy_light_decomposition.hpp"

using namespace std;


class HeavyLightDecompositionTest : public ::testing::Test {
    protected:
    // heavy_light_decomposition_testcase1
    vector<vector<size_t>> graph1() {
        vector<vector<size_t>> G(9);
        G[0] = { 1 };
        G[1] = { 0, 2, 4 };
        G[2] = { 1, 3 };
        G[3] = { 2 };
        G[4] = { 1, 5 };
        G[5] = { 4, 6, 7 };
        G[6] = { 5, 8 };
        G[7] = { 5 };
        G[8] = { 6 };
        return G;
    }
    // heavy_light_decomposition_testcase2
    vector<vector<size_t>> graph2() {
        vector<vector<size_t>> G(14);
        G[0] = { 1, 2, 3 };
        G[1] = { 0, 4, 5 };
        G[2] = { 0, 6 };
        G[3] = { 0, 7, 8 };
        G[4] = { 1 };
        G[5] = { 1, 9 };
        G[6] = { 2, 12 };
        G[7] = { 3 };
        G[8] = { 3, 13 };
        G[9] = { 5, 10, 11 };
        G[10] = { 9 };
        G[11] = { };
        G[12] = { };
        G[13] = { };
        return G;
    }
};

TEST_F(HeavyLightDecompositionTest, IsEmptyInitially) {
    HeavyLightDecomposition hld;
    EXPECT_EQ(0ULL, hld.size());
}

TEST_F(HeavyLightDecompositionTest, CanBuildLater) {
    HeavyLightDecomposition hld;
    EXPECT_EQ(0ULL, hld.size());

    auto G = graph1();
    hld.build(G, { 0 });
    EXPECT_EQ(G.size(), hld.size());
}

TEST_F(HeavyLightDecompositionTest, ShouldGetIndex) {
    auto G = graph2();
    auto hld = HeavyLightDecomposition(G, { 0 });

    EXPECT_EQ(0ULL, hld.get_index(0));
    EXPECT_EQ(1ULL, hld.get_index(1));
    EXPECT_EQ(2ULL, hld.get_index(5));
    EXPECT_EQ(3ULL, hld.get_index(9));
    EXPECT_EQ(4ULL, hld.get_index(10));
    EXPECT_EQ(5ULL, hld.get_index(11));
    EXPECT_EQ(6ULL, hld.get_index(4));
    EXPECT_EQ(7ULL, hld.get_index(2));
    EXPECT_EQ(8ULL, hld.get_index(6));
    EXPECT_EQ(9ULL, hld.get_index(12));
    EXPECT_EQ(10ULL, hld.get_index(3));
    EXPECT_EQ(11ULL, hld.get_index(8));
    EXPECT_EQ(12ULL, hld.get_index(13));
    EXPECT_EQ(13ULL, hld.get_index(7));
}

TEST_F(HeavyLightDecompositionTest, ShouldGetVertex) {
    auto G = graph2();
    auto hld = HeavyLightDecomposition(G, { 0 });

    EXPECT_EQ(0ULL, hld.get_vertex(0));
    EXPECT_EQ(1ULL, hld.get_vertex(1));
    EXPECT_EQ(5ULL, hld.get_vertex(2));
    EXPECT_EQ(9ULL, hld.get_vertex(3));
    EXPECT_EQ(10ULL, hld.get_vertex(4));
    EXPECT_EQ(11ULL, hld.get_vertex(5));
    EXPECT_EQ(4ULL, hld.get_vertex(6));
    EXPECT_EQ(2ULL, hld.get_vertex(7));
    EXPECT_EQ(6ULL, hld.get_vertex(8));
    EXPECT_EQ(12ULL, hld.get_vertex(9));
    EXPECT_EQ(3ULL, hld.get_vertex(10));
    EXPECT_EQ(8ULL, hld.get_vertex(11));
    EXPECT_EQ(13ULL, hld.get_vertex(12));
    EXPECT_EQ(7ULL, hld.get_vertex(13));
}

TEST_F(HeavyLightDecompositionTest, ShouldGetParent) {
    auto G = graph2();
    auto hld = HeavyLightDecomposition(G, { 0 });
    EXPECT_EQ(14ULL, hld.get_parent(0));
    EXPECT_EQ(0ULL, hld.get_parent(1));
    EXPECT_EQ(0ULL, hld.get_parent(2));
    EXPECT_EQ(0ULL, hld.get_parent(3));
    EXPECT_EQ(1ULL, hld.get_parent(4));
    EXPECT_EQ(1ULL, hld.get_parent(5));
    EXPECT_EQ(2ULL, hld.get_parent(6));
    EXPECT_EQ(3ULL, hld.get_parent(7));
    EXPECT_EQ(3ULL, hld.get_parent(8));
    EXPECT_EQ(5ULL, hld.get_parent(9));
    EXPECT_EQ(9ULL, hld.get_parent(10));
    EXPECT_EQ(9ULL, hld.get_parent(11));
    EXPECT_EQ(6ULL, hld.get_parent(12));
    EXPECT_EQ(8ULL, hld.get_parent(13));
}

TEST_F(HeavyLightDecompositionTest, ShouldComputeAtSubtreeVertex) {
    auto G = graph2();
    auto hld = HeavyLightDecomposition(G, { 0 });

    hld.for_subtree_vertex(5, [&](auto l, auto r) {
        EXPECT_EQ(2ULL, l);
        EXPECT_EQ(6ULL, r);
    });

    hld.for_subtree_vertex(3, [&](auto l, auto r) {
        EXPECT_EQ(10ULL, l);
        EXPECT_EQ(14ULL, r);
    });
}

TEST_F(HeavyLightDecompositionTest, ShouldComputeAtSubtreeEdge) {
    auto G = graph2();
    auto hld = HeavyLightDecomposition(G, { 0 });

    hld.for_subtree_edge(5, [&](auto l, auto r) {
        EXPECT_EQ(3ULL, l);
        EXPECT_EQ(6ULL, r);
    });

    hld.for_subtree_edge(3, [&](auto l, auto r) {
        EXPECT_EQ(11ULL, l);
        EXPECT_EQ(14ULL, r);
    });
}

TEST_F(HeavyLightDecompositionTest, ShouldIterateEachVertex) {
    auto G = graph2();
    auto hld = HeavyLightDecomposition(G, { 0 });

    // 11 -> 13
    {
        vector<tuple<size_t,size_t,bool>> ts;
        hld.for_each_vertex(11, 13, [&](auto l, auto r, auto reverse) {
            ts.push_back({ l, r, reverse });
        });
        sort(ts.begin(), ts.end());
        vector<tuple<size_t,size_t,bool>> es = {
            { 0, 4, true }, { 5, 6, true }, { 10, 13, false },
        };
        EXPECT_EQ(es, ts);
    }

    // 13 -> 11
    {
        vector<tuple<size_t,size_t,bool>> ts;
        hld.for_each_vertex(13, 11, [&](auto l, auto r, auto reverse) {
            ts.push_back({ l, r, reverse });
        });
        sort(ts.begin(), ts.end());
        vector<tuple<size_t,size_t,bool>> es = {
            { 0, 4, false }, { 5, 6, false }, { 10, 13, true },
        };
        EXPECT_EQ(es, ts);

    }

}

TEST_F(HeavyLightDecompositionTest, ShouldIterateEachEdge) {
    auto G = graph2();
    auto hld = HeavyLightDecomposition(G, { 0 });

    // 11 -> 13
    {
        vector<tuple<size_t,size_t,bool>> ts;
        hld.for_each_edge(11, 13, [&](auto l, auto r, auto reverse) {
            ts.push_back({ l, r, reverse });
        });
        sort(ts.begin(), ts.end());
        vector<tuple<size_t,size_t,bool>> es = {
            { 1, 4, true }, { 5, 6, true }, { 10, 13, false },
        };
        EXPECT_EQ(es, ts);
    }

    // 13 -> 11
    {
        vector<tuple<size_t,size_t,bool>> ts;
        hld.for_each_edge(13, 11, [&](auto l, auto r, auto reverse) {
            ts.push_back({ l, r, reverse });
        });
        sort(ts.begin(), ts.end());
        vector<tuple<size_t,size_t,bool>> es = {
            { 1, 4, false }, { 5, 6, false }, { 10, 13, true },
        };
        EXPECT_EQ(es, ts);
    }

}

TEST_F(HeavyLightDecompositionTest, ShouldReduceEachVertex) {
    auto G = graph2();
    auto hld = HeavyLightDecomposition(G, { 0 });

    vector<int> A(G.size() + 1, 1);
    for (size_t i = 1; i < A.size(); ++i) {
        A[i] += A[i-1];
    }
    function<int(size_t,size_t,bool)> valuef = [&](auto l, auto r, auto reverse) {
        return A[r] - A[l];
    };
    function<int(int)> inversef = [](auto v) { return v; };
    function<int(int const&, int const&)> mergef = [&](auto const& av, auto const& bv) {
        return av + bv;
    };

    EXPECT_EQ(8, hld.reduce_each_vertex<int>(11, 13, valuef, inversef, mergef));
    EXPECT_EQ(2, hld.reduce_each_vertex<int>(9, 11, valuef, inversef, mergef));
    EXPECT_EQ(2, hld.reduce_each_vertex<int>(11, 9, valuef, inversef, mergef));
    EXPECT_EQ(5, hld.reduce_each_vertex<int>(4, 6, valuef, inversef, mergef));
    EXPECT_EQ(5, hld.reduce_each_vertex<int>(7, 5, valuef, inversef, mergef));
}

TEST_F(HeavyLightDecompositionTest, ShouldReduceEachEdge) {
    auto G = graph2();
    auto hld = HeavyLightDecomposition(G, { 0 });

    function<int(size_t,size_t,bool)> valuef = [&](auto l, auto r, auto reverse) {
        if (l == r) return 0;
        auto u = hld.get_vertex(l);
        auto v = hld.get_vertex(r-1);
        auto s = reverse ? -1 : 1;
        auto ans =  s * (int)(hld.distance(u, v) + 1);
        return ans;
    };
    function<int(int)> inversef = [](auto v) { return v; };
    function<int(int const&, int const&)> mergef = [&](auto const& av, auto const& bv) {
        return av + bv;
    };

    EXPECT_EQ(-1, hld.reduce_each_edge<int>(11, 13, valuef, inversef, mergef));
    EXPECT_EQ(1, hld.reduce_each_edge<int>(9, 11, valuef, inversef, mergef));
    EXPECT_EQ(-1, hld.reduce_each_edge<int>(11, 9, valuef, inversef, mergef));
    EXPECT_EQ(0, hld.reduce_each_edge<int>(4, 6, valuef, inversef, mergef));
    EXPECT_EQ(1, hld.reduce_each_edge<int>(7, 9, valuef, inversef, mergef));
}

TEST_F(HeavyLightDecompositionTest, ShouldComputeLCA) {
    auto G = graph2();
    auto hld = HeavyLightDecomposition(G, { 0 });

    EXPECT_EQ(1ULL, hld.lca(4, 9));
    EXPECT_EQ(9ULL, hld.lca(10, 11));
    EXPECT_EQ(5ULL, hld.lca(9, 5));
    EXPECT_EQ(0ULL, hld.lca(10, 2));
    EXPECT_EQ(0ULL, hld.lca(11, 12));
    EXPECT_EQ(3ULL, hld.lca(7, 13));
    EXPECT_EQ(8ULL, hld.lca(8, 13));
    EXPECT_EQ(0ULL, hld.lca(12, 8));
    EXPECT_EQ(0ULL, hld.lca(12, 7));
}

TEST_F(HeavyLightDecompositionTest, ShouldComputeDistance) {
    auto G = graph2();
    auto hld = HeavyLightDecomposition(G, { 0 });

    EXPECT_EQ(0ULL, hld.distance(0, 0));
    EXPECT_EQ(4ULL, hld.distance(0, 10));
    EXPECT_EQ(4ULL, hld.distance(0, 11));
    EXPECT_EQ(2ULL, hld.distance(1, 2));
    EXPECT_EQ(2ULL, hld.distance(10, 11));
    EXPECT_EQ(4ULL, hld.distance(4, 11));
    EXPECT_EQ(2ULL, hld.distance(5, 11));

    EXPECT_EQ(2ULL, hld.distance(2, 12));
    EXPECT_EQ(1ULL, hld.distance(6, 12));
    EXPECT_EQ(3ULL, hld.distance(0, 12));

    EXPECT_EQ(3ULL, hld.distance(0, 13));
    EXPECT_EQ(2ULL, hld.distance(0, 7));
    EXPECT_EQ(2ULL, hld.distance(0, 8));
    EXPECT_EQ(1ULL, hld.distance(3, 8));
    EXPECT_EQ(2ULL, hld.distance(3, 13));
    EXPECT_EQ(3ULL, hld.distance(7, 13));

    EXPECT_EQ(5ULL, hld.distance(9, 6));
    EXPECT_EQ(5ULL, hld.distance(9, 7));
    EXPECT_EQ(3ULL, hld.distance(2, 8));
}