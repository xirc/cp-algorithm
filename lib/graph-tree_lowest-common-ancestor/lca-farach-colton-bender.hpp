#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C

#include <vector>
#include <cmath>
#include <algorithm>

class LCA {
    std::vector<int> first;
    std::vector<int> euler;
    std::vector<int> height;
    int block_size, block_count;
    std::vector<std::vector<int>> sparse_table;
    std::vector<int> block_mask;
    std::vector<std::vector<std::vector<int>>> blocks;

public:
    // O(N)
    LCA(std::vector<std::vector<int>>& adj) {
        build(adj);
    }
    // O(1)
    int query(int v, int u) {
        int l = first[v], r = first[u];
        if (l > r) {
            std::swap(l, r);
        }
        int bl = l / block_size, br = r / block_size;
        if (bl == br) {
            int i = query_in_block(bl, l % block_size, r % block_size);
            return euler[i];
        }
        int ans1 = query_in_block(bl, l % block_size, block_size - 1);
        int ans2 = query_in_block(br, 0, r % block_size);
        int ans = min_by_height(ans1, ans2);
        if (br - bl <= 1) {
            return euler[ans];
        }
        int w = (int)log2(br - bl - 1);
        int ans3 = sparse_table[bl + 1][w];
        int ans4 = sparse_table[br - (1 << w)][w];
        ans = min_by_height(ans, ans3);
        ans = min_by_height(ans, ans4);
        return euler[ans];
    }

private:
    // O(N)
    void build(std::vector<std::vector<int>>& adj, int root = 0) {
        const int N = adj.size();

        // Get euler tour & indice of first occurences.
        first.assign(N, -1);
        height.assign(N, 0);
        euler.reserve(2 * N);
        dfs_euler(adj, root, -1, 0);

        const int M = euler.size();
        block_size = std::max(1, (int)std::log2(M) / 2);
        block_count = std::ceil((double)M / block_size);

        // Compute minimum of each block and build sparse table.
        // O(N)
        const int LB = (int)std::log2(block_count) + 1;
        sparse_table.assign(block_count, std::vector<int>(LB, 0));
        for (int i = 0; i < M; ++i) {
            int j = i % block_size, b = i / block_size;
            if (j == 0 || min_by_height(i, sparse_table[b][0]) == i) {
                sparse_table[b][0] = i;
            }
        }
        for (int w = 1; w < LB; ++w) {
            for (int i = 0; i < block_count; ++i) {
                int j = i + (1 << (w - 1));
                if (j >= block_count) {
                    sparse_table[i][w] = sparse_table[i][w-1];
                } else {
                    sparse_table[i][w] =
                        min_by_height(sparse_table[i][w-1], sparse_table[j][w-1]);
                }
            }
        }

        // Compute a mask for each block.
        // O(sqrtN)
        block_mask.assign(block_count, 0);
        for (int i = 0; i < M; ++i) {
            int j = i % block_size, b = i / block_size;
            if (j == 0) continue;
            if (min_by_height(i - 1, i) == i - 1) {
                block_mask[b] += 1 << (j - 1);
            }
        }

        // Compute RMQ for each unique block
        // O(sqrtN logN logN)
        blocks.resize(1 << (block_size - 1));
        for (int b = 0; b < block_count; ++b) {
            int mask = block_mask[b];
            if (!blocks[mask].empty()) continue;
            blocks[mask].assign(block_size, std::vector<int>(block_size));
            for (int l = 0; l < block_size; ++l) {
                blocks[mask][l][l] = l;
                for (int r = l + 1; r < block_size; ++r) {
                    blocks[mask][l][r] = blocks[mask][l][r-1];
                    int base = b * block_size;
                    if (base + r >= M) continue;
                    blocks[mask][l][r] =
                        min_by_height(base + blocks[mask][l][r], base + r) - base;
                }
            }
        }
    }
    // O(N)
    void dfs_euler(std::vector<std::vector<int>>& adj, int v, int p, int h) {
        euler.push_back(v);
        first[v] = euler.size() - 1;
        height[v] = h;
        for (int u : adj[v]) {
            if (u == p) continue;
            dfs_euler(adj, u, v, h + 1);
            euler.push_back(v);
        }
    }
    int min_by_height(int i, int j) {
        return height[euler[i]] < height[euler[j]] ? i : j;
    }
    // [l,r] inclusive
    int query_in_block(int b, int l, int r) {
        return blocks[block_mask[b]][l][r] + b * block_size;
    }
};