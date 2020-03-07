#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A

#include <vector>
#include <cmath>
#include <algorithm>

template <class T, class Monoid>
class SqrtDecomposition {
    std::vector<T> m_array;
    std::vector<T> m_block;
    int N, S;
public:
    SqrtDecomposition(){}
    int size() { return N; }
    void dump(std::vector<T>& buffer) {
        buffer.resize(m_array.size());
        std::copy(m_array.begin(), m_array.end(), buffer.begin());
    }
    // O(N)
    void build(std::vector<T>& array) {
        N = array.size();
        S = std::ceil(std::sqrt(N));
        m_array.assign(N, 0);
        m_block.assign(S, Monoid::id());
        std::copy(array.begin(), array.end(), m_array.begin());
        for (int i = 0; i < N; ++i) {
            m_block[i / S] = Monoid::op(m_block[i / S], m_array[i]);
        }
    }
    // [l..r)
    // O(sqrt(N))
    T query(int l, int r) {
        l = std::max(l, 0);
        r = std::min(r, N);
        T ans = Monoid::id();
        int cl = l / S, cr = (r - 1) / S;
        if (cl == cr) {
            for (int i = l; i < r; ++i) {
                ans = Monoid::op(ans, m_array[i]);
            }
        } else {
            for (int i = l, M = (cl+1)*S; i < M; ++i) {
                ans = Monoid::op(ans, m_array[i]);
            }
            for (int i = cl + 1; i < cr; ++i) {
                ans = Monoid::op(ans, m_block[i]);
            }
            for (int i = cr * S; i < r; ++i) {
                ans = Monoid::op(ans, m_array[i]);
            }
        }
        return ans;
    }
    // Update value at array[index]
    // O(sqrt(N))
    void update(int index, T value) {
        if (index < 0 || index > N) return;
        m_array[index] = value;
        int bi = index / S;
        m_block[bi] = Monoid::id();
        for (int i = bi * S; i < (bi+1)*S; ++i) {
            m_block[bi] = Monoid::op(m_block[bi], m_array[i]);
        }
    }
};