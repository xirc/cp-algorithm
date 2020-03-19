#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A

#include <vector>
#include <queue>
#include <algorithm>

// Maximum Flow
// Preflow Push-Relabel Algorithm
// Memory: O(V^2)
class MaximumFlow {
    static const long long inf = 1e18;
    static const int inf_int = 1e8;
    struct edge {
        int from, to;
        long long capacity;
    };

    int N;
    std::vector<edge> edges;
    std::vector<std::vector<long long>> capacity, flow;
    // Temporal
    int S;
    long long maxflow;
    std::queue<int> excess_vertices;
    std::vector<int> height, seen;
    std::vector<long long> excess;

public:
    // O(V^2)
    MaximumFlow(int n)
        : N(n)
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
        edges.push_back({ from, to, capacity });
        edges.push_back({ to, from, 0 });
        this->capacity[from][to] += capacity;
    }
    // O(E)
    void clear_flow() {
        flow.assign(N, std::vector<long long>(N, 0));
    }
    // O(V^2)
    std::vector<std::vector<long long>> get_flow() {
        return flow;
    }
    // O(V^2 E)
    // NOTE: This memorizes the residual network.
    long long solve(int s, int t) {
        throw_if_invalid_index(s);
        throw_if_invalid_index(t);

        excess_vertices = std::queue<int>();
        height.assign(N, 0);
        excess.assign(N, 0);
        seen.assign(N, 0);

        S = s;
        maxflow = 0;
        height[s] = N;
        excess[s] = inf;
        for (int u = 0; u < N; ++u) {
            push(s, u);
        }

        while (!excess_vertices.empty()) {
            int u = excess_vertices.front(); excess_vertices.pop();
            if (u == s || u == t) continue;
            discharge(u);
        }

        return maxflow;
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
            excess_vertices.push(v);
        }
        if (u == S) maxflow += d;
        if (v == S) maxflow -= d;
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