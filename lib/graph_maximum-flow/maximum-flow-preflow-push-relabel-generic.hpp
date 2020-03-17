#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A

#include <vector>
#include <queue>
#include <algorithm>

class MaximumFlow {
    static const long long inf = 1e18;
    static const int inf_int = 1e8;
    struct edge {
        int from, to;
        long long capacity;
    };

    int N;
    std::vector<edge> edges;
    // Temporal
    std::queue<int> excess_verts;
    std::vector<std::vector<long long>> capacity, flow;
    std::vector<int> height, seen;
    std::vector<long long> excess;

public:
    // O(1)
    MaximumFlow(int size): N(size) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to, long long capacity) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        edges.push_back({ from, to, capacity });
        edges.push_back({ to, from, 0 });
    }
    // O(V^2 E)
    long long solve(int s, int t, std::vector<std::vector<long long>>& out_flow) {
        throw_if_invalid_index(s);
        throw_if_invalid_index(t);

        excess_verts = std::queue<int>();
        capacity.assign(N, std::vector<long long>(N, 0));
        flow.assign(N, std::vector<long long>(N, 0));
        height.assign(N, 0);
        excess.assign(N, 0);
        seen.assign(N, 0);

        for (auto e : edges) {
            capacity[e.from][e.to] += e.capacity;
        }
        height[s] = N;
        excess[s] = inf;
        for (int u = 0; u < N; ++u) {
            push(s, u);
        }

        while (!excess_verts.empty()) {
            int u = excess_verts.front(); excess_verts.pop();
            if (u == s || u == t) continue;
            discharge(u);
        }

        out_flow = flow;
        long long max_flow = 0;
        for (int u = 0; u < N; ++u) {
            max_flow += flow[s][u];
        }
        return max_flow;
    }

private:
    void throw_if_invalid_index(int i) {
        if (i < 0 || i >= N) throw "index out of range";
    }
    void discharge(int u) {
        while (excess[u] > 0) {
            if (seen[u] < N) {
                int v = seen[u];
                if (capacity[u][v] - flow[u][v] > 0 && height[u] > height[v]) {
                    push(u, v);
                } else {
                    seen[u]++;
                }
            } else {
                relabel(u);
                seen[u] = 0;
            }
        }
    }
    void push(int u, int v) {
        long long d = std::min(excess[u], capacity[u][v] - flow[u][v]);
        flow[u][v] += d;
        flow[v][u] -= d;
        excess[u] -= d;
        excess[v] += d;
        if (d > 0 && excess[v] == d) {
            excess_verts.push(v);
        }
    }
    void relabel(int u) {
        auto h = inf_int;
        for (int v = 0; v < N; ++v) {
            if (capacity[u][v] - flow[u][v] > 0) {
                h = std::min(h, height[v]);
            }
        }
        if (h < inf_int) {
            height[u] = h + 1;
        }
    }
};