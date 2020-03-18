#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B

#include <vector>
#include <queue>
#include <algorithm>

// Topological Sort
class TopologicalSort {
    int N;
    std::vector<std::vector<int>> adj;

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
    bool solve(std::vector<int>& ans) {
        std::queue<int> Q;
        std::vector<int> in(N, 0);

        ans.clear();
        ans.reserve(N);

        for (int v = 0; v < N; ++v) {
            for (int u : adj[v]) in[u]++;
        }
        for (int v = 0; v < N; ++v) {
            if (in[v] == 0) Q.push(v);
        }
        while (Q.size()) {
            int v = Q.front(); Q.pop();
            ans.push_back(v);
            for (auto u : adj[v]) {
                in[u]--;
                if (in[u] == 0) Q.push(u);
            }
        }
        return ans.size() == N;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};