#pragma once

// Verified
// x http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667

#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <tuple>

class HeavyLightDecomposition {
    int N;
    std::vector<int> index, inverse, out, head, heavy, parent, depth, subsize;

public:
    // O(N)
    HeavyLightDecomposition(
        const std::vector<std::vector<int>>& adj,
        std::vector<int> R = std::vector<int>({0})
    )
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
    void for_each_subtree_vertex(int u, const std::function<void(int,int)>& f) {
        throw_if_invalid_index(u);
        f(index[u], out[u]);
    }
    // O(1)
    // f [l,r)
    void for_each_subtree_edge(int u, const std::function<void(int,int)>& f) {
        throw_if_invalid_index(u);
        f(index[u]+1, out[u]);
    }
    // O(logN)
    // f [l,r)
    void for_each_vertex(int u, int v, const std::function<void(int,int)>& f) {
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
    void for_each_edge(int u, int v, const std::function<void(int,int)>& f) {
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
    void build(const std::vector<std::vector<int>>& adj, const std::vector<int>& R) {
        int pos = 0;
        for (auto v : R) {
            dfs_prepare(adj, v);
            dfs_decompose(adj, v, pos);
        }
    }
    // O(N)
    // NOTE: Don't use a recursive call for strict constraints.
    void dfs_prepare(const std::vector<std::vector<int>>& adj, int s) {
        std::stack<std::pair<int,int>> S;
        parent[s] = -1;
        depth[s] = 0;
        S.push({s,0});
        while (S.size()) {
            int v = S.top().first;
            int &i = S.top().second;
            if (i == -1) {
                i++;
                subsize[v] = 1;
            } else if (i < adj[v].size()) {
                int u = adj[v][i++];
                if (u == parent[v]) continue;
                parent[u] = v;
                depth[u] = depth[v] + 1;
                S.push({u, -1});
            } else {
                S.pop();
                int max_size = 0;
                for (auto u : adj[v]) {
                    if (parent[v] == u) continue;
                    subsize[v] += subsize[u];
                    if (subsize[u] > max_size) {
                        max_size = subsize[u];
                        heavy[v] = u;
                    }
                }
            }
        }
    }
    // O(N)
    // NOTE: Don't use a recursive call for strict constraints.
    void dfs_decompose(const std::vector<std::vector<int>>& adj, int s, int& pos) {
        std::stack<std::tuple<int,int,int>> S;
        S.push(std::make_tuple(s,s,-1));
        while (S.size()) {
            int v = std::get<0>(S.top());
            int h = std::get<1>(S.top());
            int &i = std::get<2>(S.top());
            if (i == -1) {
                i++;
                head[v] = h;
                index[v] = pos;
                inverse[pos] = v;
                pos++;
                if (heavy[v] != -1) {
                    S.push(std::make_tuple(heavy[v],h,-1));
                }
            } else if (i < adj[v].size()) {
                int u = adj[v][i++];
                if (parent[v] == u) continue;
                if (heavy[v] == u) continue;
                S.push(std::make_tuple(u,u,-1));
            } else {
                out[v] = pos;
                S.pop();
            }
        }
    }
};