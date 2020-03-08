#pragma once

#include <vector>
#include <algorithm>

// SegmentTree (RangeUpdate,RangeQuery)
// Memory O(N)
// Build  O(N)
// Query O(log N)
// Update O(log N)
template<class T, class QueryMonoid, class UpdateMonoid, class Push>
class SegmentTree {
protected:
    int m_size;
    std::vector<T> m_tree;

public:
    SegmentTree(int n)
        : m_size(n)
        , m_tree(n*4, UpdateMonoid::id())
    {
        // Do nothing
    }
    // O(1)
    int size() {
        return m_size;
    }
    // O(N log N)
    void dump(std::vector<T>& buffer) {
        if (buffer.capacity() < m_size) {
            buffer.reserve(m_size);
        }
        buffer.clear();
        for (int i = 0; i < m_size; ++i) {
            buffer.push_back(query(i,i+1));
        }
    }
    // O(N)
    void build(std::vector<T>& array) {
        m_size = array.size();
        m_tree.resize(m_size * 4);
        std::fill(m_tree.begin(), m_tree.end(), UpdateMonoid::id());
        build(array, 0, 0, m_size);
    }
    // O(log N)
    T query(int l, int r) {
        return query(0, 0, m_size, max(l,0), min(r,m_size)).max;
    }
    // O(log N)
    void update(int l, int r, T value) {
        update(0, 0, m_size, l, r, value);
    }

protected:
    static constexpr int left(int v) {
        return v * 2 + 1;
    }
    static constexpr int right(int v) {
        return v * 2 + 2;
    }
    void build(std::vector<T>& array, int v, int tl, int tr) {
        if (tr - tl == 1) {
            m_tree[v] = UpdateMonoid::op(m_tree[v], array[tl]);
        } else {
            const int tm = (tl + tr) / 2;
            build(array, left(v), tl, tm);
            build(array, right(v), tm, tr);
            m_tree[v] = QueryMonoid::op(m_tree[left(v)], m_tree[right(v)]);
        }
    }
    T query(int v, int tl, int tr, int l, int r) {
        if (l >= r) {
            return QueryMonoid::id();
        }
        Push::pushdown(m_tree[v], m_tree[left(v)], m_tree[right(v)]);
        if (l == tl && r == tr) {
            return m_tree[v];
        }
        const int tm = (tl + tr) / 2;
        const auto lhs = query(left(v), tl, tm, l, min(r,tm));
        const auto rhs = query(right(v), tm, tr, max(l,tm), r);
        return QueryMonoid::op(lhs, rhs);
    }
    void update(int v, int tl, int tr, int l, int r, T value) {
        if (l >= r) {
            return;
        }
        Push::pushdown(m_tree[v], m_tree[left(v)], m_tree[right(v)]);
        if (l == tl && r == tr) {
            m_tree[v] = UpdateMonoid::op(m_tree[v], value);
        } else {
            const int tm = (tl + tr) / 2;
            update(left(v), tl, tm, l, min(r, tm), value);
            update(right(v), tm, tr, max(l,tm), r, value);
            m_tree[v] = QueryMonoid::op(m_tree[left(v)], m_tree[right(v)]);
        }
    }
};