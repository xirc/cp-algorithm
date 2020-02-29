#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A

#include <vector>
#include <queue>
#include <algorithm>

class MaximumFlow {
    static const long long inf = 1e18;
    struct edge { int to; long long capacity; };
    int m_size;
    std::vector<std::vector<edge>> adj;
    // Temporal variables
    std::vector<std::vector<long long>> capacity, flow;

public:
    MaximumFlow(int size): m_size(size), adj(size) {}
    int size() {
        return m_size;
    }
    void add_edge(int from, int to, long long capacity) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        adj[from].push_back({ to, capacity });
        adj[to].push_back({ from, 0 });
    }
    // O(V E^2)
    long long solve(int s, int t, std::vector<std::vector<long long>>& out_flow) {
        throw_if_invalid_index(s);
        throw_if_invalid_index(t);

        const int N = m_size;
        capacity.assign(N, std::vector<long long>(N, 0));
        for (int u = 0; u < N; ++u) {
            for (auto e : adj[u]) {
                capacity[u][e.to] += e.capacity;
            }
        }
        flow.assign(N, std::vector<long long>(N, 0));

        long long ans = 0;
        while (auto new_flow = bfs(s, t)) {
            ans += new_flow;
        }

        out_flow = flow;
        return ans;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index out of range";
    }
    // O(E)
    long long bfs(int s, int t) {
        const int N = m_size;
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