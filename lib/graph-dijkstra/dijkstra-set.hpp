#pragma once

#include <vector>
#include <set>

// Use Dijkstra(ver: set<>) if the peformance is very important.
// If you use the complex data structure in set<>,
// use Dijkstra(ver: priority_queue<>) which is better performance in such case.
class Dijkstra {
    struct edge { int to; long long distance; };
    int m_size;
    std::vector<std::vector<edge>> adj;
    static std::vector<long long> distance;

public:
    static const long long inf = 1e18;

    Dijkstra(int size) : m_size(size), adj(size) {
    }

    int size() {
        return m_size;
    }

    void add_edge(int from, int to, long long distance) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        if (distance < 0) throw;
        adj[from].push_back({ to, distance });
    }

    // O(V log V + E)
    void solve(int s, std::vector<long long>& D, std::vector<int>& P) {
        throw_if_invalid_index(s);

        distance.assign(m_size, inf);
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
                int to = edge.to; long long len = edge.distance;
                if (distance[v] + len < distance[to]) {
                    Q.erase(to); // Do first for the Q's consistency.
                    distance[to] = distance[v] + len;
                    P[to] = v;
                    Q.insert(to);
                }
            }
        }

        // Copy from the temporary buffer.
        D = std::vector<long long>(distance.begin(), distance.end());
    }
private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index out of range";
    }
};
std::vector<long long> Dijkstra::distance = std::vector<long long>();