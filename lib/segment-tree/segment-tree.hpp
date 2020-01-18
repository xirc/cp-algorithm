#pragma once

#include <algorithm>
#include <vector>

// SegmentTree (PointUpdate,RangeQuery)
// Memory O(N)
// Build  O(N)
// Query O(log N)
// Update O(log N)
template<class T, class Monoid>
class SegmentTree {
protected:
    int m_size;
    std::vector<T> m_array;
    std::vector<T> m_tree;

public:
    SegmentTree(int n)
        : m_size(n)
        , m_array(n)
        , m_tree(n*4, Monoid::id())
    {
        // Do nothing
    }

    // O(1)
    int size() {
        return m_size;
    }

    // O(N)
    void build(std::vector<T>& array) {
        m_size = array.size();
        m_array.resize(m_size);
        std::fill(m_array.begin(), m_array.end(), Monoid::id());
        m_tree.resize(m_size * 4);
        std::fill(m_tree.begin(), m_tree.end(), Monoid::id());
        build(array, 0, 0, m_size);
    }

    // find the value in range [l, r)
    // O(log N)
    T query(int l, int r) {
        return query(0, 0, m_size, std::max(l,0), std::min(r,m_size));
    }

    // update the value at index which is in range [0, n)
    // O(log N)
    bool update(int index, T value) {
        if (index < 0 || index >= m_size) {
            return false;
        }
        update(0, 0, m_size, index, value);
        return true;
    }

    // O(N)
    void dump(std::vector<T>& buffer) {
        if (buffer.capacity() < m_size) {
            buffer.reserve(m_size);
        }
        buffer.clear();
        for (int i = 0; i < m_size; ++i) {
            buffer.push_back(m_array[i]);
        }
    }

protected:
    static constexpr int left(int v) {
        return v * 2 + 1;
    }

    static constexpr int right(int v) {
        return v * 2 + 2;
    }

    void build(std::vector<T>& array, int v, int tl, int tr) {
        if (tr - tl <= 0) {
            return;
        }
        if (tr - tl == 1) {
            m_array[tl] = array[tl];
            m_tree[v] = Monoid::op(array[tl], Monoid::id());
        } else {
            const int tm = (tl + tr) / 2;
            const int vl = left(v), vr = right(v);
            build(array, vl, tl, tm);
            build(array, vr, tm, tr);
            m_tree[v] = Monoid::op(m_tree[vl], m_tree[vr]);
        }
    }

    T query(int v, int tl, int tr, int l, int r) {
        if (l >= r) {
            return Monoid::id();
        }
        if (l == tl && r == tr) {
            return m_tree[v];
        }
        const int tm = (tl + tr) / 2;
        const int vl = left(v), vr = right(v);
        const auto sl = query(vl, tl, tm, l, std::min(r,tm));
        const auto sr = query(vr, tm, tr, std::max(l,tm), r);
        return Monoid::op(sl, sr);
    }

    void update(int v, int tl, int tr, int index, T value) {
        if (tr - tl <= 0) {
            return;
        }
        if (tr - tl == 1) {
            m_array[tl] = value;
            m_tree[v] = Monoid::op(value, Monoid::id());
        } else {
            const int tm = (tl + tr) / 2;
            const int vl = left(v), vr = right(v);
            if (index < tm) {
                update(vl, tl, tm, index, value);
            } else {
                update(vr, tm, tr, index, value);
            }
            m_tree[v] = Monoid::op(m_tree[vl], m_tree[vr]);
        }
    }
};