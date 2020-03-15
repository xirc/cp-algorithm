#pragma once

#include <vector>
#include <set>

// SegmentTree (PointUpdate,RangeQuery)
// Memory O(N log N)
// Build O(N log^2 N)
// Query O(log^2 N)
// Update O(log^2 N) 
template<class T>
class SegmentTree {
public:
    using value_type_T = T;
    using value_type_E = T;

protected:
    int N;
    std::vector<T> m_array;
    std::vector<std::multiset<T>> m_tree;

public:
    SegmentTree(int n)
    {
        build(std::vector<T>(n));
    }

    // O(1)
    int size() {
        return N;
    }

    // O(N log^2 N)
    void build(const std::vector<T>& array) {
        N = array.size();
        m_array.resize(N);
        m_tree.resize(N * 4, std::multiset<T>());
        build(array, 0, 0, N);
    }

    // O(log^2 N)
    template<class Query>
    T query(int l, int r, T value, const Query& Q) {
        return query(0, 0, N, l, r, value, Q);
    }

    // O(log^2 N)
    bool update(int index, T value) {
        if (index < 0 || index >= N) {
            return false;
        }
        update(0, 0, N, index, value);
        return true;
    }

    // O(N)
    void dump(std::vector<T>& buffer) {
        buffer.clear();
        for (int i = 0; i < N; ++i) {
            buffer.push_back(m_array[i]);
        }
    }

protected:
    static constexpr int left(int v) { return v * 2 + 1; }
    static constexpr int right(int v) { return v * 2 + 2; }
    void build(const std::vector<T>& array, int v, int tl, int tr) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            m_array[tl] = array[tl];
            m_tree[v].clear();
            m_tree[v].insert(array[tl]);
        } else {
            const int tm = (tl + tr) / 2;
            const int vl = left(v), vr = right(v);
            build(array, vl, tl, tm);
            build(array, vr, tm, tr);
            m_tree[v].clear();
            m_tree[v].insert(m_tree[vl].begin(), m_tree[vl].end());
            m_tree[v].insert(m_tree[vr].begin(), m_tree[vr].end());
        }
    }

    template <class Query>
    T query(int v, int tl, int tr, int l, int r, T x, const Query& Q) {
        if (l >= r) {
            return Q.id;
        }
        if (l == tl && r == tr) {
            return Q(m_tree[v], x);
        }
        const int tm = (tl + tr) / 2;
        const int vl = left(v), vr = right(v);
        const auto lhs = query(vl, tl, tm, l, std::min(r, tm), x, Q);
        const auto rhs = query(vr, tm, tr, std::max(l, tm), r, x, Q);
        return Q(lhs, rhs);
    }
    void update(int v, int tl, int tr, int index, T value) {
        if (tr - tl <= 0) return;
        // Erase just one element, and insert new value.
        m_tree[v].erase(m_tree[v].find(m_array[index]));
        m_tree[v].insert(value);
        if (tr - tl == 1) {
            m_array[index] = value;
        } else {
            const int tm = (tl + tr) / 2;
            const int vl = left(v), vr = right(v);
            if (index < tm) {
                update(vl, tl, tm, index, value);
            } else {
                update(vr, tm, tr, index, value);
            }
        }
    }
};