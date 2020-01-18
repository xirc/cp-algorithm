#pragma once

#include <algorithm>
#include <vector>

struct vertex {
    vertex *left, *right;
    int sum;
    vertex(int value)
        : left(nullptr)
        , right(nullptr)
        , sum(value)
    {
        // Do nothing
    }
    vertex(vertex *left, vertex *right)
        : left(left), right(right), sum(0)
    {
        if (left) sum += left->sum;
        if (right) sum += right->sum;
    }
};

class SegmentTree {
    int m_size;
    std::vector<vertex*> m_history;

public:
    SegmentTree() {
        build(0);
    }
    SegmentTree(int n) {
        build(n);
    }
    int history_size() {
        return m_history.size();
    }
    // O(N)
    void build(int n) {
        std::vector<int> array(std::max(n,0));
        build(array); // for simplicity
    }
    // O(N)
    void build(std::vector<int>& array) {
        m_history.clear();
        m_size = array.size();
        if (m_size == 0) {
            m_history.emplace_back(new vertex(0));
        } else {
            const auto root = build(array, 0, m_size);
            m_history.emplace_back(root);
        }
    }
    // O(log N)
    // Find the sum in segments [l,r)
    int sum(int l, int r, int hindex = 0) {
        auto root = history(hindex);
        if (!root) {
            return 0;
        }
        return sum(root, l, r);
    }
    // O(log N)
    // Update the value at index
    bool update(int index, int value) {
        if (index < 0 || index >= m_size) {
            return false;
        }
        const auto new_root = update(history(0), index, value);
        m_history.emplace_back(new_root);
        return true;
    }
    // O(N)
    void dump(std::vector<int>& buffer, int hindex = 0) {
        buffer.resize(m_size);
        for (int i = 0; i < m_size; ++i) {
            buffer[i] = sum(i, i + 1, hindex);
        }
    }

protected:
    vertex* history(int hindex) {
        if (hindex < 0 || hindex >= m_history.size()) {
            return nullptr;
        }
        int i = m_history.size() - hindex - 1;
        return m_history[i];
    }
    vertex* build(std::vector<int>& array, int tl, int tr) {
        if (tr - tl <= 0) return nullptr;
        if (tr - tl == 1) {
            return new vertex(array[tl]);
        }
        const int tm = (tl + tr) / 2;
        const auto lhs = build(array, tl, tm);
        const auto rhs = build(array, tm, tr);
        return new vertex(lhs, rhs);
    }
    int sum(vertex* root, int l, int r) {
        return sum(root, 0, m_size, std::max(l,0), std::min(r,m_size));
    }
    int sum(vertex* v, int tl, int tr, int l, int r) {
        if (r - l <= 0) return 0;
        if (l == tl && r == tr) {
            return v->sum;
        } else {
            const int tm = (tl + tr) / 2;
            const int lhs = sum(v->left, tl, tm, l, std::min(r,tm));
            const int rhs = sum(v->right, tm, tr, std::max(l,tm), r);
            return lhs + rhs;
        }
    }
    vertex* update(vertex* root, int index, int value) {
        if (index < 0 || index >= m_size) {
            return root;
        }
        return update(root, 0, m_size, index, value);
    }
    vertex* update(vertex* v, int tl, int tr, int index, int value) {
        if (tr - tl <= 0) return nullptr;
        if (tr - tl == 1) {
            return new vertex(value);
        }
        const int tm = (tl + tr) / 2;
        if (index < tm) {
            const auto left = update(v->left, tl, tm, index, value);
            return new vertex(left, v->right);
        } else {
            const auto right = update(v->right, tm, tr, index, value);
            return new vertex(v->left, right);
        }
    }
};