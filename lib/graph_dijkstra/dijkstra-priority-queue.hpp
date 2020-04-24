#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A

#include <vector>
#include <queue>

// Use Dijkstra(ver: priority_queue<>) in most case.
// This has better performance than Dijkstra(ver: set<>).
// Memory: O(V + E)
// NOTE: directed, multi-edge, self-loop, no-negative-weight
class Dijkstra {
    struct edge { int to; long long distance; };
    int N;
    std::vector<std::vector<edge>> adj;

public:
    static const long long inf;
    // O(V)
    Dijkstra(int n = 0) : N(n), adj(n) {
    }
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
    // O(V logV + E)
    void solve(int s, std::vector<long long>& D, std::vector<int>& P) {
        D.assign(N, inf);
        P.assign(N, -1);

        using pii = std::pair<int,int>;
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
        std::vector<bool> used(N, false);

        D[s] = 0;
        Q.push({0, s});

        while (!Q.empty()) {
            int v = Q.top().second; Q.pop();

            if (used[v]) continue;
            used[v] = true;

            for (auto edge : adj[v]) {
                int to = edge.to; long long len = edge.distance;
                if (D[v] + len < D[to]) {
                    D[to] = D[v] + len;
                    P[to] = v;
                    Q.push({D[to], to});
                }
            }
        }
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};
const long long Dijkstra::inf = 1e18;