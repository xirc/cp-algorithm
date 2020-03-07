#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B

#include <vector>
#include <algorithm>

class BellmanFord {
    struct edge { int from, to; long long cost; };
    int m_size;
    std::vector<edge> m_edges;
public:
    static const long long inf = 1e18;
    BellmanFord(int size): m_size(size) {}
    int size() {
        return m_size;
    }
    void add_edge(int from, int to, long long cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        m_edges.push_back(edge{ from, to, cost });
    }
    // O (E V)
    bool solve(int from, std::vector<long long>& D, std::vector<int>& P) {
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

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index of of range";
    }
};