#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A

#include <vector>
#include <set>

// Use Dijkstra(ver: set<>) if the peformance is very important.
// If you use the complex data structure in set<>,
// use Dijkstra(ver: priority_queue<>) which is better performance in such case.
// Memory: O(V + E)
// NOTE: directed, multi-edge, self-loop, no-negative-weight
class Dijkstra {
    struct edge { int to; long long distance; };
    int N;
    std::vector<std::vector<edge>> adj;
    static std::vector<long long> distance;

public:
    static const long long inf = 1e18;
    // O(V)
    Dijkstra(int n = 0) : N(n), adj(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to, long long distance) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        if (distance < 0) throw;
        adj[from].push_back({ to, distance });
    }
    // O(V log V + E)
    void solve(int s, std::vector<long long>& D, std::vector<int>& P) {
        throw_if_invalid_index(s);

        distance.assign(N, inf);
        P.assign(N, -1);

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
        if (index < 0 || index >= N) throw "index out of range";
    }
};
std::vector<long long> Dijkstra::distance = std::vector<long long>();