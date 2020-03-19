#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C

#include <vector>

// LCA: Lowest Common Ancestor
// Memory: O(V + E + Q)
class LCA {
    struct Query { int u, idx; };
    struct DSU {
        struct node { int parent, rank; };
        std::vector<node> nodes;
        DSU(): DSU(0) {}
        DSU(int n): nodes(n) {
            for (int i = 0; i < n; ++i) {
                nodes[i] = { i, 0 };
            }
        }
        node find_set(int v) {
            if (v != nodes[v].parent) {
                nodes[v] = find_set(nodes[v].parent);
            }
            return nodes[v];
        }
        void union_set(int u, int v) {
            u = find_set(u).parent;
            v = find_set(v).parent;
            if (u == v) return;
            if (nodes[u].rank < nodes[v].rank) {
                std::swap(u, v);
            }
            nodes[v].parent = u;
            if (nodes[u].rank == nodes[v].rank) {
                nodes[u].rank++;
            }
        }
    };

    DSU dsu;
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
        dsu = DSU(N);
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
            dsu.union_set(u, v);
            int c = dsu.find_set(v).parent;
            ancestor[c] = v;
        }
        for (auto query : queries[v]) {
            if (!visited[query.u]) continue;
            int c = dsu.find_set(query.u).parent;
            answer[query.idx] = ancestor[c];
        }
    }
};