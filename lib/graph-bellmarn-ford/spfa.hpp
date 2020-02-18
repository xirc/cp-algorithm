#pragma once

#include <vector>
#include <queue>

// More faster than Bellman-Ford on average.
class SPFA {
    const int inf = 1e8;
    struct edge { int to, cost; };
    int m_size;
    std::vector<std::vector<edge>> m_edges;
public:
    SPFA(int size): m_size(size), m_edges(size) {}
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index of of range";
    }
    int size() {
        return m_size;
    }
    void add_edge(int from, int to, int cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        m_edges[from].push_back(edge{ to, cost });
    }
    // O (E V)
    bool solve(int from, std::vector<int>& D, std::vector<int>& P) {
        const int N = m_size;
        D.assign(N, inf);
        P.assign(N, -1);
        std::vector<int> count(N, 0);
        std::vector<bool> inqueue(N, false);
        std::queue<int> Q;

        D[from] = 0;
        Q.push(from);
        inqueue[from] = true;
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            inqueue[v] = false;

            for (auto edge : m_edges[v]) {
                if (D[edge.to] <= D[v] + edge.cost) continue;
                D[edge.to] = D[v] + edge.cost;
                P[edge.to] = v;
                if (inqueue[edge.to]) continue;
                Q.push(edge.to);
                inqueue[edge.to] = true;
                count[edge.to]++;
                if (count[edge.to] > N) {
                    // Found a negative cycle
                    return false;
                }
            }
        }
        return true;
    }
};