#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C

#include <vector>
#include "../data-structure_union-find-tree/union-find-tree.hpp"

// LCA: Lowest Common Ancestor
// Memory: O(V + E + Q)
class LCA {
    struct Query { int u, idx; };

    UnionFindTree dsu;
    std::vector<bool> visited;
    std::vector<int> ancestor;
    std::vector<int> answer;

public:
    // O(V + Q)
    std::vector<int> solve(
        const std::vector<std::vector<int>>& adj,
        const std::vector<std::pair<int,int>>& queries
    ) {
        const int N = adj.size(), M = queries.size();
        std::vector<std::vector<Query>> Q(N);
        for (int i = 0; i < M; ++i) {
            const int u = queries[i].first, v = queries[i].second;
            Q[u].push_back({ v, i });
            Q[v].push_back({ u, i });
        }
        dsu = UnionFindTree(N);
        visited.assign(N, false);
        ancestor.assign(N, -1);
        answer.assign(M, -1);
        dfs(adj, Q, 0);
        return answer;
    }

private:
    void dfs(
        const std::vector<std::vector<int>>& adj,
        const std::vector<std::vector<Query>>& queries,
        int v
    ) {
        visited[v] = true;
        ancestor[v] = v;
        for (int u : adj[v]) {
            if (visited[u]) continue;
            dfs(adj, queries, u);
            dsu.unite(u, v);
            int c = dsu.find(v).leader;
            ancestor[c] = v;
        }
        for (auto query : queries[v]) {
            if (!visited[query.u]) continue;
            int c = dsu.find(query.u).leader;
            answer[query.idx] = ancestor[c];
        }
    }
};