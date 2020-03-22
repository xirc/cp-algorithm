#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A

#include <vector>
#include <queue>
#include <algorithm>

// Maximum Flow
// Edmonds&Karp Algorithm
// Memory: O(V^2)
// NOTE: directed, multi-edge, self-loop
class MaximumFlow {
    static const long long inf = 1e18;
    struct edge {
        int to;
        long long capacity;
    };

    int N;
    std::vector<std::vector<edge>> adj;
    std::vector<std::vector<long long>> capacity, flow;

public:
    // O(V)
    MaximumFlow(int n = 0)
        : N(n)
        , adj(n)
        , capacity(n, std::vector<long long>(n, 0))
        , flow(n, std::vector<long long>(n, 0))
    {
        // Do nothing
    }
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to, long long capacity) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        if (capacity < 0) throw;
        adj[from].push_back({ to, capacity });
        adj[to].push_back({ from, 0 });
        this->capacity[from][to] += capacity;
    }
    // O(V^2)
    void clear_flow() {
        flow.assign(N, std::vector<long long>(N, 0));
    }
    // O(V^2)
    std::vector<std::vector<long long>> get_flow() {
        return flow;
    }
    // O(V E^2)
    // NOTE: This memorizes the residual network.
    long long solve(int s, int t) {
        throw_if_invalid_index(s);
        throw_if_invalid_index(t);

        long long ans = 0;
        while (auto new_flow = bfs(s, t)) {
            ans += new_flow;
        }
        return ans;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    // O(E)
    long long bfs(int s, int t) {
        struct entry { int v; long long flow; };
        std::queue<entry> Q;
        std::vector<int> prev(N, -1);

        long long aug = 0;
        prev[s] = s;
        Q.push({ s, inf });

        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            int v = cur.v; long long f = cur.flow;
            if (v == t) {
                aug = f;
                break;
            }
            for (auto e : adj[v]) {
                if (prev[e.to] != -1) continue;
                auto cf = std::min(f, capacity[v][e.to] - flow[v][e.to]);
                if (cf <= 0) continue;
                prev[e.to] = v;
                Q.push({ e.to, cf });
            }
        }

        if (aug == 0) {
            return 0;
        }

        int c = t;
        while (c != s) {
            int p = prev[c]; 
            flow[p][c] += aug;
            flow[c][p] -= aug;
            c = p;
        }
        return aug;
    }
};