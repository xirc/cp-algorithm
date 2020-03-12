#pragma once

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
    TopologicalSort(int n): N(n), adj(n) {}
    int size() {
        return N;
    }
    void add_edge(int from, int to) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        adj[from].push_back(to);
    }
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