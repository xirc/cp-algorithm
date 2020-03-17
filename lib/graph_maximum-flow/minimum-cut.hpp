#pragma once

#include <vector>
#include <set>

class MinimumCut {
    struct edge { int from, to, capacity; };
    int N;
    std::vector<edge> edges;
    // Temporal
    std::vector<std::vector<long long>> capacity;
    std::vector<int> prev;

public:
    // O(1)
    MinimumCut(int size): N(size) {}
    // O(1)
    void add_edge(int from, int to, int capacity) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        edges.push_back({ from, to, capacity });
    }
    // O(MaximumFlow's Algorithm) + O(V^2)
    void solve(
        int s, int t, const std::vector<std::vector<long long>>& flow,
        std::set<int>& setS, std::set<int>& setT
    ) {
        throw_if_invalid_index(s);
        throw_if_invalid_index(t);

        capacity.assign(N, std::vector<long long>(N, 0));
        for (auto e : edges) {
            capacity[e.from][e.to] += e.capacity;
        }
        prev.assign(N, -1);
        setS.clear();
        setT.clear();
        dfs(s, flow, setS);
        for (int i = 0; i < N; ++i) {
            if (setS.count(i)) continue;
            setT.insert(i);
        }
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    // O(V^2)
    void dfs(
        int v, const std::vector<std::vector<long long>>& flow,
        std::set<int>& set
    ) {
        set.insert(v);
        for (int u = 0; u < N; ++u) {
            if (prev[u] != -1) continue;
            if (capacity[v][u] - flow[v][u] <= 0) continue;
            prev[u] = v;
            dfs(u, flow, set);
        }
    }
};