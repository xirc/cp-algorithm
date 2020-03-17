#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B

#include <vector>
#include <algorithm>

// Topological Sort
// This algorithm cannot detect a cycle.
class TopologicalSort {
    int N;
    std::vector<std::vector<int>> adj;
    // Temporal
    std::vector<int> ans;
    std::vector<bool> visited;

public:
    // O(V)
    TopologicalSort(int n): N(n), adj(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        adj[from].push_back(to);
    }
    // O(V + E)
    std::vector<int> solve() {
        std::vector<int> in(N, 0);

        ans.clear();
        visited.assign(N, false);

        for (int v = 0; v < N; ++v) {
            for (int u : adj[v]) {
                in[u]++;
            }
        }
        for (int v = 0; v < N; ++v) {
            if (in[v] > 0) continue;
            if (visited[v]) continue;
            dfs(v);
        }
        std::reverse(ans.begin(), ans.end());

        return ans;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    void dfs(int v) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u);
            }
        }
        ans.push_back(v);
    }
};