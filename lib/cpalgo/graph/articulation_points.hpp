#pragma once

#include <algorithm>
#include <stdexcept>
#include <vector>

// Articulation Points of a Graph
//
// Complexity
// Time: O(V + E)
// Space: O(V + E)
//
// NOTE:
//  - undirected
//  - multi-edge
//  - no-self-loop
//
// Verified
//  - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
//
class ArticulationPoints {
    struct edge { size_t id, to; };

    size_t N, M;
    std::vector<std::vector<edge>> adj;

    // Temporary
    size_t K;
    std::vector<size_t> tin;
    std::vector<size_t> low;
    std::vector<size_t> ans;

public:
    // O(V)
    ArticulationPoints(size_t n = 0): N(n), M(0), adj(n) {}
    // O(1)
    size_t size() const {
        return N;
    }
    // u = [0,N), v = [0,N)
    // O(1)
    void add_edge(size_t u, size_t v) {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");
        adj[u].push_back({ M, v });
        adj[v].push_back({ M, u });
        M++;
    }
    // O(V + E)
    std::vector<size_t> solve() {
        K = 0;
        tin.assign(N, N);
        low.assign(N, N);
        ans.clear();
        for (size_t u = 0; u < N; ++u) {
            if (tin[u] != N) continue;
            dfs(u, { M, N });
        }
        return ans;
    }

private:
    void dfs(size_t u, edge const& ein) {
        bool is_cutpoint = false;
        size_t childlen = 0;
        tin[u] = low[u] = K++;
        for (auto const& e : adj[u]) {
            if (tin[e.to] == N) {
                dfs(e.to, e);
                low[u] = std::min(low[u], low[e.to]);
                ++childlen;
                if (ein.id != M && tin[u] <= low[e.to]) {
                    is_cutpoint = true;
                }
            } else if (e.id != ein.id) {
                low[u] = std::min(low[u], tin[e.to]);
            }
        }
        if (ein.id == M && childlen > size_t(1)) {
            is_cutpoint = true;
        }
        if (is_cutpoint) {
            ans.push_back(u);
        }
    }
};