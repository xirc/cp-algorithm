#pragma once

#include <algorithm>
#include <stdexcept>
#include <vector>


// LCA: Lowest Common Ancestor
//   using Segment Tree
//
// Space: O(V + E)
//
// NOTE:
//  - undirected
//  - non-loop
//  - non-multi-edge
//  - it can NOT handle a forest
//
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
//
class LCASegmentTree {
    size_t N, M;
    std::vector<size_t> height, first, euler, segtree;

public:
    // root = [0,N)
    // Time: O(N)
    LCASegmentTree(
        std::vector<std::vector<size_t>> const& adj = {},
        size_t const root = 0
    )
    {
        build(adj, root);
    }
    // root = [0,N)
    // Time: O(N)
    void build(
        std::vector<std::vector<size_t>> const& adj,
        size_t const root = 0
    )
    {
        N = adj.size();

        height.assign(N, 0);
        first.assign(N, 2 * N);
        euler.assign(0, 0);
        euler.reserve(2 * N);

        if (N > 0) {
            if (root >= N) throw std::out_of_range("root");
            dfs_euler(adj, root, N, 0);
        }

        M = euler.size();
        segtree.assign(4 * M, 0);
        build_segtree(0, 0, M);
    }
    // A LCA node of both the node 'u' and the node 'v'
    // u = [0,N), v = [0,N)
    // Time: O(logN)
    size_t query(size_t const u, size_t const v) const {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");

        auto l = first[u], r = first[v];
        if (l > r) std::swap(l, r);
        return query_segtree(0, 0, M, l, r + 1);
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }

private:
    // Time: O(N)
    void dfs_euler(std::vector<std::vector<size_t>> const& adj, size_t const v, size_t const p, size_t const h) {
        height[v] = h;
        euler.push_back(v);
        first[v] = euler.size() - 1;
        for (auto const& to : adj[v]) {
            if (to == p) continue;
            dfs_euler(adj, to, v, h + 1);
            euler.push_back(v);
        }
    }
    static constexpr size_t left_segtree(size_t v) { return 2 * v + 1; }
    static constexpr size_t right_segtree(size_t v) { return 2 * v + 2; }
    // Time: O(N)
    // [tl,tr) exclusive
    void build_segtree(size_t const v, size_t const tl, size_t const tr) {
        if (tl >= tr) return;
        if (tl + 1 == tr) {
            segtree[v] = euler[tl];
        } else {
            auto const tm = (tl + tr) >> 1;
            build_segtree(left_segtree(v), tl, tm);
            build_segtree(right_segtree(v), tm, tr);
            auto const lhs = segtree[left_segtree(v)], rhs = segtree[right_segtree(v)];
            segtree[v] = (height[lhs] < height[rhs]) ? lhs : rhs;
        }
    }
    // Time: O(logN)
    // [l,r) exclusive
    size_t query_segtree(size_t const v, size_t const tl, size_t const tr, size_t const l, size_t const r) const {
        if (tl >= tr || l >= r) {
            return N;
        }
        if (tl == l && tr == r) {
            return segtree[v];
        }
        auto const tm = (tl + tr) >> 1;
        auto const lhs = query_segtree(left_segtree(v), tl, tm, l, std::min(r,tm));
        auto const rhs = query_segtree(right_segtree(v), tm, tr, std::max(l,tm), r);
        if (lhs == N) return rhs;
        if (rhs == N) return lhs;
        return height[lhs] < height[rhs] ? lhs : rhs;
    }
};