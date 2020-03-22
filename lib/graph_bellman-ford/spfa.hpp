#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B

#include <vector>
#include <queue>

// Shortest Path Faster Algorithm
// More faster than Bellman-Ford on average.
// Memory: O(V + E)
// NOTE: directed, multi-edge, self-loop, negative-weight
class SPFA {
    struct edge { int to; long long cost; };
    int N;
    std::vector<std::vector<edge>> edges;

public:
    static const long long inf = 1e18;
    // O(V)
    SPFA(int n = 0): N(n), edges(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to, long long cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        edges[from].push_back({ to, cost });
    }
    // O (E V)
    bool solve(int from, std::vector<long long>& D, std::vector<int>& P) {
        D.assign(N, inf);
        P.assign(N, -1);
        std::vector<int> count(N, 0);
        std::vector<bool> inqueue(N, false);
        std::queue<int> Q;

        D[from] = 0;
        Q.push(from);
        inqueue[from] = true;
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            inqueue[v] = false;

            for (auto edge : edges[v]) {
                if (D[edge.to] <= D[v] + edge.cost) continue;
                D[edge.to] = D[v] + edge.cost;
                P[edge.to] = v;
                if (inqueue[edge.to]) continue;
                Q.push(edge.to);
                inqueue[edge.to] = true;
                count[edge.to]++;
                if (count[edge.to] > N) {
                    // Found a negative cycle
                    return false;
                }
            }
        }
        return true;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index of of range";
    }
};