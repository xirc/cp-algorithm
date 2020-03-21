#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B

#include <vector>
#include <algorithm>
#include <tuple>

// Bridges of a Graph
// Memory: O(V + E)
// NOTE: undirected, multi-edge, no-self-loop
class Bridges {
    struct edge { int u, v; };
    struct entry { int id, to; };

    int N;
    std::vector<edge> edges;
    std::vector<std::vector<entry>> adj;
    // Temporary
    int K;
    std::vector<int> ord;
    std::vector<int> low;
    std::vector<std::tuple<int,int,int>> ans;

public:
    // O(V)
    Bridges(int n): N(n), adj(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int u, int v) {
        throw_if_invalid_index(u, N);
        throw_if_invalid_index(v, N);
        edges.push_back({ u, v });
        int id = edges.size() - 1;
        adj[u].push_back({ id, v });
        adj[v].push_back({ id, u });
    }
    // O(V + E)
    std::vector<std::tuple<int,int,int>> solve() {
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
    void throw_if_invalid_index(int index, int M) {
        if (index < 0 || index > M) throw "index out of range";
    }
    void dfs(int u, const entry& ein = { -1, 0 }) {
        ord[u] = low[u] = K++;
        for (auto& e : adj[u]) {
            if (ord[e.to] == -1) {
                dfs(e.to, e);
                low[u] = std::min(low[u], low[e.to]);
                if (ord[u] < low[e.to]) {
                    ans.push_back(
                        std::make_tuple(e.id, edges[e.id].u, edges[e.id].v)
                    );
                }
            } else if (e.id != ein.id) {
                low[u] = std::min(low[u], ord[e.to]);
            }
        }
    }
};