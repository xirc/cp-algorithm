#pragma once

#include <vector>
#include <algorithm>
#include <functional>

class HeavyLightDecomposition {
    using mat = const std::vector<std::vector<int>>;
    using func = std::function<void(int,int)>;
    int N;
    std::vector<int> index, inverse, out, head, heavy, parent, depth, subsize;

public:
    // O(N)
    HeavyLightDecomposition(mat& adj, std::vector<int> R = std::vector<int>({0}))
        : N(adj.size())
        , index(N,-1)
        , inverse(N,-1)
        , out(N,-1)
        , head(N,-1)
        , heavy(N,-1)
        , parent(N,-1)
        , depth(N,0)
        , subsize(N,0)
    {
        build(adj, R);
    }
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    int get_index(int v) {
        return index[v];
    }
    // O(1)
    int get_vertex(int index) {
        return inverse[index];
    }
    // O(1)
    int get_parent(int v) {
        return parent[v];
    }
    // O(1)
    // f [l,r)
    void for_each_subtree_node(int u, const func& f) {
        throw_if_invalid_index(u);
        f(index[u], out[u]);
    }
    // O(1)
    // f [l,r)
    void for_each_subtree_edge(int u, const func& f) {
        throw_if_invalid_index(u);
        f(index[u]+1, out[u]);
    }
    // O(logN)
    // f [l,r)
    void for_each_vertex(int u, int v, const func& f) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        for (; head[u] != head[v]; v = parent[head[v]]) {
            if (index[u] > index[v]) {
                std::swap(u, v);
            }
            f(index[head[v]], index[v]+1);
        }
        if (index[u] > index[v]) {
            std::swap(u, v);
        }
        f(index[u], index[v]+1);
    }
    // O(logN)
    // f [l,r)
    void for_each_edge(int u, int v, const func& f) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        for (; head[u] != head[v]; v = parent[head[v]]) {
            if (index[u] > index[v]) {
                std::swap(u, v);
            }
            f(index[head[v]], index[v]+1);
        }
        if (index[u] > index[v]) {
            std::swap(u, v);
        }
        f(index[u]+1, index[v]+1);
    }
    // O(logN)
    int lca(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        while (true) {
            if (index[u] > index[v]) {
                std::swap(u, v);
            }
            if (head[u] == head[v]) {
                return u;
            }
            v = parent[head[v]];
        }
    }
    // O(logN)
    int distance(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        return depth[u] + depth[v] - 2 * depth[lca(u,v)];
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    // O(N)
    void build(mat& adj, const std::vector<int>& R) {
        int pos = 0;
        for (auto v : R) {
            dfs_prepare(adj, v);
            dfs_decompose(adj, v, v, pos);
        }
    }
    // O(N)
    void dfs_prepare(const mat& adj, int v) {
        int max_size = 0;
        subsize[v] = 1;
        for (int u : adj[v]) {
            if (u == parent[v]) continue;
            parent[u] = v;
            depth[u] = depth[v] + 1;
            dfs_prepare(adj, u);
            subsize[v] += subsize[u];
            if (subsize[u] > max_size) {
                max_size = subsize[u];
                heavy[v] = u;
            }
        }
    }
    // O(N)
    void dfs_decompose(mat& adj, int v, int h, int& pos) {
        head[v] = h;
        index[v] = pos;
        inverse[pos] = v;
        pos++;
        if (heavy[v] != -1) {
            dfs_decompose(adj, heavy[v], h, pos);
        }
        for (int u : adj[v]) {
            if (parent[v] == u) continue;
            if (heavy[v] == u) continue;
            dfs_decompose(adj, u, u, pos);
        }
        out[v] = pos;
    }
};