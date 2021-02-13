#pragma once

#include <stdexcept>
#include <vector>
#include "cpalgo/ds/union_find_tree.hpp"


// LCA: Lowest Common Ancestor
//   using Tarjan
//
// NOTE:
//  - Offline Algorithm
//
// Space: O(V + E + Q)
//
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
//
inline std::vector<size_t> lca(
    std::vector<std::vector<size_t>> const& adj,
    std::vector<std::pair<size_t,size_t>> const& queries
)
{
    const size_t N = adj.size(), M = queries.size();

    struct Query { size_t u; size_t idx; };
    std::vector<std::vector<Query>> Q(N);
    for (size_t i = 0; i < M; ++i) {
        const size_t u = queries[i].first, v = queries[i].second;
        Q[u].push_back({ v, i });
        Q[v].push_back({ u, i });
    }

    UnionFindTree dsu(N);
    std::vector<bool> visited(N, false);
    std::vector<size_t> ancestor(N, N);
    std::vector<size_t> answer(M, N);

    std::function<void(size_t)> const dfs = [&](size_t v) {
        visited[v] = true;
        ancestor[v] = v;
        for (auto const& u : adj[v]) {
            if (visited[u]) continue;
            dfs(u);
            dsu.unite(u, v);
            size_t c = dsu.find(v).leader;
            ancestor[c] = v;
        }
        for (auto const& query : Q[v]) {
            if (!visited[query.u]) continue;
            size_t c = dsu.find(query.u).leader;
            answer[query.idx] = ancestor[c];
        }
    };
    dfs(0);

    return answer;
}