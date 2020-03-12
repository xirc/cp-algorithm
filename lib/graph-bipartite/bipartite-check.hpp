#pragma once

#include <vector>
#include <queue>

class BipartiteCheck {
    int N;
    std::vector<std::vector<int>> adj;

public:
    BipartiteCheck(int n): N(n), adj(n) {}
    int size() {
        return N;
    }
    void add_edge(int from, int to) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        adj[from].push_back(to);
    }
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