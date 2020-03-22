#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B

#include <vector>
#include <queue>
#include <tuple>

// Height of a Tree
// Memory: O(V + E)
// NOTE: undirected, no-negative-weight
class TreeHeight {
    struct edge {
        int to;
        long long w;
    };
    int N;
    std::vector<std::vector<edge>> adj;

public:
    static const long long inf = 1e18;
    // O(V)
    TreeHeight(int n = 0): N(n), adj(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int u, int v, long long w) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        if (w < 0) throw;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    // O(V + E)
    std::vector<long long> solve(int s = 0) {
        int u, v;
        long long w;

        std::tie(u, v, w) = diameter(s);
        auto Du = distance(u);
        auto Dv = distance(v);

        std::vector<long long> ans(N, 0);
        for (int i = 0; i < N; ++i) {
            if (i == u || i == v) {
                ans[i] = w;
            } else {
                ans[i] = std::max(Du[i], Dv[i]);
            }
        }
        return ans;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    std::tuple<int, int, long long> diameter(int s) {
        int u, v;
        long long w;
        std::tie(u, w) = farther(s);
        std::tie(v, w) = farther(u);
        return std::make_tuple(u, v, w);
    }
    std::vector<long long> distance(int s) {
        std::vector<long long> D(N, inf);
        std::queue<int> Q;
        Q.push(s);
        D[s] = 0;
        while (Q.size()) {
            int u = Q.front(); Q.pop();
            for (auto& e : adj[u]) {
                if (D[e.to] == inf) {
                    D[e.to] = D[u] + e.w;
                    Q.push(e.to);
                }
            }
        }
        return D;
    }
    std::pair<int, long long> farther(int s) {
        auto D = distance(s);
        int v = -1;
        for (int i = 0; i < N; ++i) {
            if (D[i] == inf) continue;
            if (v == -1 || D[i] > D[v]) {
                v = i;
            }
        }
        return std::make_pair(v, D[v]);
    }
};