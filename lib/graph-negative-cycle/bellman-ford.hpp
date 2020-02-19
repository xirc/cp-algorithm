#pragma once

#include <vector>
#include <algorithm>

class BellmanFord {
    struct edge { int from, to, cost; };
    int m_size;
    std::vector<edge> m_edges;
public:
    BellmanFord(int size): m_size(size) {}
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index out of range";
    }
    int size() {
        return m_size;
    }
    void add_edge(int from, int to, int cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        m_edges.push_back(edge{ from, to, cost });
    }
    // O(VE)
    bool solve(std::vector<int>& cycle) {
        const int N = m_size;
        std::vector<int> D(N);
        std::vector<int> P(N, -1);
        int x;
        for (int i = 0; i < N; ++i) {
            x = -1;
            for (auto e : m_edges) {
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
};