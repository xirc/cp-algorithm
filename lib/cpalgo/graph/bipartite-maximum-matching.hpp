#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A

#include <vector>

// Bipartite Maximum Matching
// Memory: O(V + E)
// NOTE: undirected, bipartite
class BipartiteMaximumMatching {
    int N;
    std::vector<std::vector<int>> adj;
    // Temporal
    std::vector<int> match;
    std::vector<bool> used;

public:
    // O(N)
    BipartiteMaximumMatching(int n = 0): N(n), adj(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // O(V(V+E))
    int solve(std::vector<int>& out_match) {
        int ans = 0;
        match.assign(N, -1);
        for (int v = 0; v < N; ++v) {
            if (match[v] != -1) continue;
            used.assign(N, false);
            if (dfs(v)) ans++;
        }
        out_match = std::vector<int>(match);
        return ans;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    bool dfs(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            int w = match[u];
            if (w == -1 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
};