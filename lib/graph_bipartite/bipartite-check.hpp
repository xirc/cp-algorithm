#pragma once

#include <vector>
#include <queue>

class BipartiteCheck {
    int N;
    std::vector<std::vector<int>> adj;

public:
    // O(V)
    BipartiteCheck(int n): N(n), adj(n) {}
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
    // O(V)
    bool solve() {
        bool is_bipartite = true;
        std::vector<int> side(N, -1);
        std::queue<int> Q;
        for (int i = 0; i < N; ++i) {
            if (side[i] != -1) continue;
            Q.push(i);
            side[i] = 0;
            while (Q.size()) {
                int v = Q.front(); Q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        Q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
        return is_bipartite;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};