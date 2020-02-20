#pragma once

#include <vector>
#include <algorithm>

class BellmanFord {
    static const int inf = 1e8;
    struct edge { int from, to, cost; };
    int m_size;
    std::vector<edge> m_edges;
public:
    BellmanFord(int size): m_size(size) {}
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index of of range";
    }
    int size() {
        return m_size;
    }
    void add_edge(int from, int to, int cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        m_edges.push_back(edge{ from, to, cost });
    }
    // O (E V)
    bool solve(int from, std::vector<int>& D, std::vector<int>& P) {
        throw_if_invalid_index(from);
        D.assign(m_size, inf);
        P.assign(m_size, -1);

        bool any_update = false;
        D[from] = 0;
        for (int i = 0; i < m_size; ++i) {
            any_update = false;
            for (int j = 0; j < m_edges.size(); ++j) {
                auto e = m_edges[j];
                if (D[e.from] >= inf) continue;
                if (D[e.to] > D[e.from] + e.cost) {
                    // suppress negative overflow
                    D[e.to] = std::max(-inf, D[e.from] + e.cost);
                    P[e.to] = e.from;
                    any_update = true;
                }
            }
            if (!any_update) break;
        }

        // if any_update == true, a negative cycle is found.
        return !any_update;
    }
};