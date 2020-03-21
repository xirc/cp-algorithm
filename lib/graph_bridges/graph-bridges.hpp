#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B

#include <vector>
#include <algorithm>

// Bridges of a Graph
// Memory: O(V + E)
// NOTE: undirected, multi-edge, no-self-loop
class Bridges {
    struct edge { int id, to; };

    int N, M;
    std::vector<std::vector<edge>> adj;
    // Temporary
    int K;
    std::vector<int> ord;
    std::vector<int> low;
    std::vector<std::pair<int,int>> ans;

public:
    // O(V)
    Bridges(int n): N(n), M(0), adj(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        adj[u].push_back({ M, v });
        adj[v].push_back({ M, u });
        M++;
    }
    // O(V + E)
    std::vector<std::pair<int,int>> solve() {
        K = 0;
        ord.assign(N, -1);
        low.assign(N, -1);
        ans.clear();
        for (int u = 0; u < N; ++u) {
            if (ord[u] != -1) continue;
            dfs(u);
        }
        return ans;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index > N) throw "index out of range";
    }
    void dfs(int u, const edge& ein = { -1, 0 }) {
        ord[u] = low[u] = K++;
        for (auto& e : adj[u]) {
            if (ord[e.to] == -1) {
                dfs(e.to, e);
                low[u] = std::min(low[u], low[e.to]);
                if (ord[u] < low[e.to]) {
                    ans.push_back({ u, e.to });
                }
            } else if (e.id != ein.id) {
                low[u] = std::min(low[u], ord[e.to]);
            }
        }
    }
};