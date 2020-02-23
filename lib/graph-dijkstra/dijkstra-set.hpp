#pragma once

#include <vector>
#include <set>

// Use Dijkstra(ver: set<>) if the peformance is very important.
// If you use the complex data structure in set<>,
// use Dijkstra(ver: priority_queue<>) which is better performance in such case.
class Dijkstra {
    static const int infinity = 1e9;
    int m_size;
    std::vector<std::vector<std::pair<int,int>>> adj;
    static std::vector<int> distance;

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
        adj[a].push_back({b, len});
    }

    // O(V log V + E)
    void solve(int s, std::vector<int>& D, std::vector<int>& P) {
        distance.assign(m_size, infinity);
        P.assign(m_size, -1);

        // For the performance, Avoid the maintenance cost of a complex data structure in Q.
        struct custom_less {
            bool operator()(const int& lhs, const int& rhs) const {
                return distance[lhs] != distance[rhs] ? distance[lhs] < distance[rhs] : lhs < rhs;
            }
        };
        std::set<int, custom_less> Q;

        distance[s] = 0;
        Q.insert(s);

        while (!Q.empty()) {
            int v = *Q.begin();
            Q.erase(Q.begin());

            for (auto edge : adj[v]) {
                int to = edge.first, len = edge.second;
                if (distance[v] + len < distance[to]) {
                    Q.erase(to); // Do first for the Q's consistency.
                    distance[to] = distance[v] + len;
                    P[to] = v;
                    Q.insert(to);
                }
            }
        }

        // Copy from the temporary buffer.
        D = std::vector<int>(distance.begin(), distance.end());
    }
};
std::vector<int> Dijkstra::distance = std::vector<int>();