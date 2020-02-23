#pragma once

#include <vector>
#include <queue>

// Use Dijkstra(ver: priority_queue<>) in most case.
// This has better performance than Dijkstra(ver: set<>).
class Dijkstra {
    static const int infinity = 1e9;
    int m_size;
    std::vector<std::vector<std::pair<int,int>>> adj;

public:
    Dijkstra(int size) : m_size(size) {
        adj.assign(size, std::vector<std::pair<int,int>>());
    }

    int size() {
        return m_size;
    }

    void add_dir_edge(int a, int b, int len) {
        if (a < 0 || a >= m_size) throw;
        if (b < 0 || b >= m_size) throw;
        if (len < 0) throw;
        adj[a].push_back({b, len});
    }

    // O(V log V + E)
    void solve(int s, std::vector<int>& D, std::vector<int>& P) {
        D.assign(m_size, infinity);
        P.assign(m_size, -1);

        using pii = std::pair<int,int>;
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
        std::vector<bool> used(m_size, false);

        D[s] = 0;
        Q.push({0, s});

        while (!Q.empty()) {
            int v = Q.top().second; Q.pop();

            if (used[v]) continue;
            used[v] = true;

            for (auto edge : adj[v]) {
                int to = edge.first, len = edge.second;
                if (D[v] + len < D[to]) {
                    D[to] = D[v] + len;
                    P[to] = v;
                    Q.push({D[to], to});
                }
            }
        }
    }
};