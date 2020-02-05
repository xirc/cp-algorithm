#pragma once

#include <vector>
#include <cmath>
#include <algorithm>

class SqrtDecomposition {
    std::vector<int> m_array;
    std::vector<int> m_block;
    int N, S;
public:
    SqrtDecomposition(){}
    int size() { return N; }
    void dump(vector<int>& buffer) {
        buffer.resize(m_array.size());
        std::copy(m_array.begin(), m_array.end(), buffer.begin());
    }
    // O(N)
    void build(std::vector<int>& array) {
        N = array.size();
        S = sqrt(N) + 1;
        m_array.assign(N, 0);
        m_block.assign(S, INT_MIN);
        std::copy(array.begin(), array.end(), m_array.begin());
        for (int i = 0; i < N; ++i) {
            m_block[i / S] = std::max(m_block[i / S], m_array[i]);
        }
    }
    // sum of array [l..r)
    // O(sqrt(N))
    int query(int l, int r) {
        l = std::max(l, 0);
        r = std::min(r, N);
        int ans = INT_MIN;
        int cl = l / S, cr = (r - 1) / S;
        if (cl == cr) {
            for (int i = l; i < r; ++i) {
                ans = std::max(ans, m_array[i]);
            }
        } else {
            for (int i = l, M = (cl+1)*S; i < M; ++i) {
                ans = std::max(ans, m_array[i]);
            }
            for (int i = cl + 1; i < cr; ++i) {
                ans = std::max(ans, m_block[i]);
            }
            for (int i = cr * S; i < r; ++i) {
                ans = std::max(ans, m_array[i]);
            }
        }
        return ans;
    }
    // Update value at array[index]
    // O(sqrt(N))
    void update(int index, int value) {
        if (index < 0 || index > N) return;
        m_array[index] = value;
        int bi = index / S;
        m_block[bi] = INT_MIN;
        for (int i = bi * S; i < (bi+1)*S; ++i) {
            m_block[bi] = std::max(m_block[bi], m_array[i]);
        }
    }
};