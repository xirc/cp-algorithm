#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A

#include <vector>
#include <set>
#include <queue>

// Maximum Flow
// MPM Algorithm
// Memory: O(V^2)
// NOTE: directed, multi-edge, self-loop
class MaximumFlow {
    static const long long inf = 1e18;
    struct edge {
        int from, to;
        long long capacity, flow;
    };

    int N;
    std::vector<edge> edges;
    std::vector<std::vector<int>> adj;
    // Temporal
    std::vector<bool> alive;
    std::vector<int> level;
    std::vector<long long> pin, pout;
    std::vector<std::set<int>> in, out;

public:
    // O(V)
    MaximumFlow(int size): N(size), adj(size) {}
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
        adj[from].push_back(edges.size() - 2);
        adj[to].push_back(edges.size() - 1);
    }
    // O(E)
    void clear_flow() {
        for (auto& e : edges) {
            e.flow = 0;
        }
    }
    // O(V^2)
    std::vector<std::vector<long long>> get_flow() {
        std::vector<std::vector<long long>> flow(N, std::vector<long long>(N, 0));
        for (auto& e : edges) {
            flow[e.from][e.to] += e.flow;
        }
        return flow;
    }
    // O(V^3)
    // NOTE: This memorizes the residual network.
    long long solve(int s, int t) {
        throw_if_invalid_index(s);
        throw_if_invalid_index(t);

        long long ans = 0;
        while (true) {
            if (!bfs(s, t)) break;

            build(s, t);

            alive.assign(N, true);
            while (true) {
                int v = find_reference_node();
                if (v == -1) break;
                auto f = pot(v);
                if (f == 0) {
                    remove_node(v);
                    continue;
                }
                ans += f;
                push(v, s, f, false);
                push(v, t, f, true);
                remove_node(v);
            }
        }

        return ans;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    bool bfs(int s, int t) {
        std::queue<int> Q;
        level.assign(N, -1);
        level[s] = 0;
        Q.push(s);
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            for (int id : adj[v]) {
                auto& e = edges[id];
                if (e.capacity - e.flow <= 0) continue;
                if (level[e.to] != -1) continue;
                level[e.to] = level[v] + 1;
                Q.push(e.to);
            }
        }
        return level[t] != -1;
    }
    void build(int s, int t) {
        pin.assign(N, 0);
        pout.assign(N, 0);
        in.assign(N, std::set<int>());
        out.assign(N, std::set<int>());
        for (int i = 0; i < edges.size(); ++i) {
            auto& e = edges[i];
            if (e.capacity - e.flow <= 0) continue;
            if (level[e.from] + 1 != level[e.to]) continue;
            if (e.to != t && level[e.to] >= level[t]) continue;
            in[e.to].insert(i);
            out[e.from].insert(i);
            auto cf = e.capacity - e.flow;
            pin[e.to] += cf;
            pout[e.from] += cf;
        }
        pin[s] = pout[t] = inf;
    }
    long long pot(int v) {
        return std::min(pin[v], pout[v]);
    }
    int find_reference_node() {
        int v = -1;
        for (int i = 0; i < N; ++i) {
            if (!alive[i]) continue;
            if (v == -1 || pot(i) < pot(v)) {
                v = i;
            }
        }
        return v;
    }
    void remove_node(int v) {
        alive[v] = false;
        for (int i : in[v]) {
            auto e = edges[i];
            auto it = out[e.from].find(i);
            out[e.from].erase(it);
            pout[e.from] -= e.capacity - e.flow;
        }
        for (int i : out[v]) {
            auto e = edges[i];
            auto it = in[e.to].find(i);
            in[e.to].erase(it);
            pin[e.to] -= e.capacity - e.flow;
        }
    }
    void push(int from, int to, long long f, bool forward) {
        std::queue<int> Q;
        std::vector<long long> excess(N, 0);

        excess[from] = f;
        Q.push(from);
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            if (v == to) {
                break;
            }
            auto it = forward ? out[v].begin() : in[v].begin();
            while (excess[v] > 0) {
                auto& e = edges[*it];
                auto& er = edges[*it^1];
                int u = forward ? e.to : e.from;
                auto push = std::min(excess[v], e.capacity - e.flow);

                if (push == 0) {
                    break;
                }

                if (forward) {
                    pout[v] -= push;
                    pin[u] -= push;
                } else {
                    pin[v] -= push;
                    pout[u] -= push;
                }
                if (excess[u] == 0) {
                    Q.push(u);
                }
                excess[u] += push;
                e.flow += push;
                er.flow -= push;
                excess[v] -= push;

                if (e.capacity - e.flow > 0) {
                    break;
                }

                if (forward) {
                    in[u].erase(*it);
                    out[v].erase(*it);
                    it = out[v].begin();
                } else {
                    out[u].erase(*it);
                    in[v].erase(*it);
                    it = in[v].begin();
                }
            }
        }
    }
};