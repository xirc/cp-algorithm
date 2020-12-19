#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B

#include <vector>
#include <queue>
#include <algorithm>

// Minimum Cost Flow
// Memory: O(V + E)
// NOTE: directed, multi-edge, self-loop, negative-cost
class MinimumCostFlow {
    static const long long inf;
    struct edge {
        int from, to;
        long long capacity, cost, flow;
    };

    int N;
    std::vector<edge> edges;
    std::vector<std::vector<int>> adj;

public:
    // O(N)
    MinimumCostFlow(int n = 0): N(n), adj(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to, long long capacity, long long cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        if (capacity < 0) throw;
        edges.push_back({ from, to, capacity, cost, 0 });
        edges.push_back({ to, from, 0, -cost, 0 });
        adj[from].push_back(edges.size() - 2);
        adj[to].push_back(edges.size() - 1);
    }
    // O(V^2 E^2)
    void solve(int s, int t, long long K, long long& flow, long long& cost) {
        std::vector<long long> D;
        std::vector<int> E;

        flow = 0;
        cost = 0;
        for (auto& e : edges) {
            e.flow = 0;
        }

        while (flow < K) {
            spfa(s, D, E);
            if (D[t] == inf) {
                break;
            }

            long long f = K - flow;
            int c = t;
            while (c != s) {
                auto& e = edges[E[c]];
                f = std::min(f, e.capacity - e.flow);
                c = e.from;
            }

            flow += f;
            cost += f * D[t];
            c = t;
            while (c != s) {
                auto& e = edges[E[c]];
                auto& r = edges[E[c]^1];
                e.flow += f;
                r.flow -= f;
                c = e.from;
            }
        }
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    void spfa(int s, std::vector<long long>& D, std::vector<int>& E) {
        std::vector<bool> inQ(N, false);
        std::queue<int> Q;

        D.assign(N, inf);
        D[s] = 0;
        E.assign(N, - 1);
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            inQ[u] = false;
            for (auto id : adj[u]) {
                auto e = edges[id];
                if (e.capacity - e.flow <= 0) continue;
                if (D[e.to] <= D[u] + e.cost) continue;
                D[e.to] = D[u] + e.cost;
                E[e.to] = id;
                if (!inQ[e.to]) {
                    inQ[e.to] = true;
                    Q.push(e.to);
                }
            }
        }
    }
};
const long long MinimumCostFlow::inf = 1e18;