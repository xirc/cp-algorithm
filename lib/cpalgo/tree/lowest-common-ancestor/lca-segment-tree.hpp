#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C

#include <vector>
#include <algorithm>

// LCA: Lowest Common Ancestor
// Memory: O(V + E)
// NOTE: undirected
class LCA {
    int N, M;
    std::vector<int> height, first, euler, segtree;

public:
    // O(N)
    LCA(const std::vector<std::vector<int>>& adj = {}, int root = 0) {
        build(adj, root);
    }
    // O(N)
    void build(const std::vector<std::vector<int>>& adj, int root = 0) {
        N = adj.size();

        height.assign(N, 0);
        first.assign(N, 0);
        euler.assign(0, 0);
        euler.reserve(2 * N);

        if (N > 0) {
            dfs_euler(adj, root);
        }

        M = euler.size();
        segtree.assign(4 * M, 0);
        build_segtree(0, 0, M);
    }
    // O(logN)
    int query(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);

        int l = first[u], r = first[v];
        if (l > r) {
            std::swap(l, r);
        }
        return query_segtree(0, 0, M, l, r + 1);
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    // O(N)
    void dfs_euler(const std::vector<std::vector<int>>& adj, int v, int p = -1, int h = 0) {
        height[v] = h;
        euler.push_back(v);
        first[v] = euler.size() - 1;
        for (auto to : adj[v]) {
            if (to == p) continue;
            dfs_euler(adj, to, v, h + 1);
            euler.push_back(v);
        }
    }
    static constexpr int left_segtree(int v) { return 2 * v + 1; }
    static constexpr int right_segtree(int v) { return 2 * v + 2; }
    // O(N)
    void build_segtree(int v, int tl, int tr) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            segtree[v] = euler[tl];
        } else {
            int tm = (tl + tr) / 2;
            build_segtree(left_segtree(v), tl, tm);
            build_segtree(right_segtree(v), tm, tr);
            int lhs = segtree[left_segtree(v)], rhs = segtree[right_segtree(v)];
            segtree[v] = (height[lhs] < height[rhs]) ? lhs : rhs;
        }
    }
    // O(logN)
    // [l,r) exclusive
    int query_segtree(int v, int tl, int tr, int l, int r) {
        if (tr - tl <= 0 || r - l <= 0) {
            return -1;
        }
        if (tl == l && tr == r) {
            return segtree[v];
        }
        int tm = (tl + tr) / 2;
        int lhs = query_segtree(left_segtree(v), tl, tm, l, std::min(r,tm));
        int rhs = query_segtree(right_segtree(v), tm, tr, std::max(l,tm), r);
        if (lhs == -1) return rhs;
        if (rhs == -1) return lhs;
        return height[lhs] < height[rhs] ? lhs : rhs;
    }
};