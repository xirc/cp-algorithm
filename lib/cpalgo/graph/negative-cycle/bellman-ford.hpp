#pragma once

#include <vector>
#include <algorithm>

// Finding a negative cycle
// Memory: O(V + E)
class BellmanFord {
    struct edge {
        int from, to;
        long long cost;
    };
    int N;
    std::vector<edge> edges;

public:
    // O(1)
    BellmanFord(int n = 0): N(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to, long long cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        edges.push_back({ from, to, cost });
    }
    // O(VE)
    bool solve(std::vector<int>& cycle) {
        std::vector<long long> D(N, 0);
        std::vector<int> P(N, -1);
        int x;
        for (int i = 0; i < N; ++i) {
            x = -1;
            for (auto e : edges) {
                if (D[e.to] <= D[e.from] + e.cost) continue;
                D[e.to] = D[e.from] + e.cost;
                P[e.to] = e.from;
                x = e.to;
            }
        }
        if (x == -1) {
            return false;
        } else {
            for (int i = 0; i < N; ++i) {
                x = P[x];
            }
            cycle.clear();
            for (int v = x; v != x || cycle.size() == 0; v = P[v]) {
                cycle.push_back(v);
            }
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};