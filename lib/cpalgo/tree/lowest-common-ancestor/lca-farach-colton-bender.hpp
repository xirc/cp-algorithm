#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <vector>


// LCA: Lowest Common Ancestor
//   using Farach Colton Bender
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
class LCA {
    size_t N;
    std::vector<size_t> first;
    std::vector<size_t> height;
    std::vector<size_t> euler;
    size_t block_size, block_count;
    std::vector<std::vector<size_t>> sparse_table;
    std::vector<size_t> block_mask;
    std::vector<std::vector<std::vector<size_t>>> blocks;

public:
    // root = [0,N)
    // Time: O(N)
    LCA(
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

        // Get euler tour & indice of first occurences.
        first.assign(N, 2 * N);
        height.assign(N, 0);
        euler.assign(0, 2 * N);
        euler.reserve(2 * N);
        if (N > 0) {
            dfs_euler(adj, root, N, 0);
        }

        size_t const M = euler.size();
        block_size = std::max(size_t(1), (size_t)std::log2(std::max(size_t(1),M)) / 2);
        block_count = std::max(size_t(1), (size_t)std::ceil((double)M / block_size));

        // Compute minimum of each block and build sparse table.
        // Time: O(N)
        size_t const LB = (size_t)std::log2(block_count) + 1;
        sparse_table.assign(block_count, std::vector<size_t>(LB, 0));
        for (size_t i = 0; i < M; ++i) {
            size_t j = i % block_size, b = i / block_size;
            if (j == 0 || min_by_height(i, sparse_table[b][0]) == i) {
                sparse_table[b][0] = i;
            }
        }
        for (size_t w = 1; w < LB; ++w) {
            for (size_t i = 0; i < block_count; ++i) {
                size_t j = i + (1 << (w - 1));
                if (j >= block_count) {
                    sparse_table[i][w] = sparse_table[i][w-1];
                } else {
                    sparse_table[i][w] =
                        min_by_height(sparse_table[i][w-1], sparse_table[j][w-1]);
                }
            }
        }

        // Compute a mask for each block.
        // Time: O(sqrt(N))
        block_mask.assign(block_count, 0);
        for (size_t i = 0; i < M; ++i) {
            size_t j = i % block_size, b = i / block_size;
            if (j == 0) continue;
            assert(i > 0);
            if (min_by_height(i - 1, i) == i - 1) {
                block_mask[b] += 1 << (j - 1);
            }
        }

        // Compute RMQ for each unique block
        // Time: O(sqrt(N)*log(N)*log(N))
        blocks.resize(1 << (block_size - 1));
        for (size_t b = 0; b < block_count; ++b) {
            size_t mask = block_mask[b];
            if (!blocks[mask].empty()) continue;
            blocks[mask].assign(block_size, std::vector<size_t>(block_size));
            for (size_t l = 0; l < block_size; ++l) {
                blocks[mask][l][l] = l;
                for (size_t r = l + 1; r < block_size; ++r) {
                    blocks[mask][l][r] = blocks[mask][l][r-1];
                    size_t base = b * block_size;
                    if (base + r >= M) continue;
                    blocks[mask][l][r] =
                        min_by_height(base + blocks[mask][l][r], base + r) - base;
                }
            }
        }
    }
    // A LCA node of both the node 'u' and the node 'v'
    // u = [0,N), v = [0,N)
    // Time: O(1)
    size_t query(size_t const v, size_t const u) const {
        size_t l = first[v], r = first[u];
        if (l > r) {
            std::swap(l, r);
        }
        size_t bl = l / block_size, br = r / block_size;
        if (bl == br) {
            size_t i = query_in_block(bl, l % block_size, r % block_size);
            return euler[i];
        }
        size_t ans1 = query_in_block(bl, l % block_size, block_size - 1);
        size_t ans2 = query_in_block(br, 0, r % block_size);
        size_t ans = min_by_height(ans1, ans2);
        if (bl + 1 >= br) {
            return euler[ans];
        }
        size_t w = (size_t)log2(br - bl - 1);
        size_t ans3 = sparse_table[bl + 1][w];
        size_t ans4 = sparse_table[br - (1 << w)][w];
        ans = min_by_height(ans, ans3);
        ans = min_by_height(ans, ans4);
        return euler[ans];
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }

private:
    // Time: O(N)
    void dfs_euler(std::vector<std::vector<size_t>> const& adj, size_t const v, size_t const p, size_t const h) {
        euler.push_back(v);
        first[v] = euler.size() - 1;
        height[v] = h;
        for (auto const& u : adj[v]) {
            if (u == p) continue;
            dfs_euler(adj, u, v, h + 1);
            euler.push_back(v);
        }
    }
    // Time: O(1)
    size_t min_by_height(size_t const i, size_t const j) const {
        return height[euler[i]] < height[euler[j]] ? i : j;
    }
    // Time: O(1)
    // [l,r] inclusive
    size_t query_in_block(size_t const b, size_t const l, size_t const r) const {
        return blocks[block_mask[b]][l][r] + b * block_size;
    }
};