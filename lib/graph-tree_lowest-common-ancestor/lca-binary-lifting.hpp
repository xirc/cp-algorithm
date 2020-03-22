#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C

#include <vector>
#include <cmath>
#include <algorithm>

// LCA: Lowest Common Ancestor
// Memory: O(V log V + E)
// NOTE: undirected
class LCA {
    int N, L;
    std::vector<int> tin, tout;
    std::vector<std::vector<int>> up;

public:
    // O(N logN)
    LCA(const std::vector<std::vector<int>>& adj = {}, int root = 0) {
        build(adj, root);
    }
    // O(N logN)
    void build(const std::vector<std::vector<int>>& adj, int root = 0) {
        N = adj.size();
        tin.assign(N, 0);
        tout.assign(N, 0);
        L = std::ceil(std::log2(std::max(1,N))) + 1;
        up.assign(N, std::vector<int>(L, 0));
        int timer = 0;
        dfs(adj, root, root, timer);
    }
    // O(logN)
    int query(int  u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);

        if (is_ancestor(u, v)) {
            return u;
        }
        if (is_ancestor(v, u)) {
            return v;
        }
        for (int i = L - 1; i >= 0; --i) {
            if (is_ancestor(up[u][i], v)) continue;
            u = up[u][i];
        }
        return up[u][0];
    }

private:
    // O(N logN)
    void dfs(const std::vector<std::vector<int>>& adj, int v, int p, int &timer) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i < L; ++i) {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        for (int u : adj[v]) {
            if (u == p) continue;
            dfs(adj, u, v, timer);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    void throw_if_invalid_index(int index){ 
        if (index < 0 || index >= N) throw "index out of range";
    }
};