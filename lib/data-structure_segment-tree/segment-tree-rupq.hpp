#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D

#include <vector>
#include <algorithm>
#include <functional>

// SegmentTree (RangeUpdate,PointQuery)
// Memory O(N)
// Build O(N)
// Query O(log N)
// Update O(log N)
template<class T, class E>
class SegmentTree {
public:
    using value_type_T = T;
    using value_type_E = E;
    using G = std::function<T(const T&, const E&)>;
    using H = std::function<E(const E&, const E&)>;

protected:
    T query_id;
    G update_op;
    H lazy_op;
    E lazy_id;
    int N, M;
    std::vector<T> tree;
    std::vector<E> lazy;

public:
    // O(N)
    SegmentTree(
        int n,
        const T& query_id,
        const G& update_op,
        const H& lazy_op, const E& lazy_id
    )
        : query_id(query_id)
        , update_op(update_op)
        , lazy_op(lazy_op)
        , lazy_id(lazy_id)
    {
        build(std::vector<T>(n, query_id));
    }
    // O(N)
    template<class Query, class Update, class Lazy>
    SegmentTree(int n, Query query, Update update, Lazy lazy)
        : SegmentTree(
            n,
            query.id,
            std::bind(&Update::operator(), update, std::placeholders::_1, std::placeholders::_2),
            std::bind(&Lazy::operator(), lazy, std::placeholders::_1, std::placeholders::_2),
            lazy.id
        )
    {
        // Do nothing
    }
    // O(1)
    int size() {
        return N;
    }
    // O(N log N)
    void dump(std::vector<T>& buffer) {
        buffer.clear();
        for (int i = 0; i < N; ++i) {
            buffer.push_back(query(i));
        }
    }
    // O(N)
    void build(const std::vector<T>& array) {
        N = array.size();
        M = N * 4;
        tree.assign(M, query_id);
        lazy.assign(M, lazy_id);
        build(array, 0, 0, N);
    }
    // O(log N)
    // index = [0,N)
    T query(int index) {
        if (index < 0 || index >= N) {
            throw;
        }
        return query(0, 0, N, index);
    }
    // O(log N)
    // [l,r)
    void update(int l, int r, const E& value) {
        update(0, 0, N, l, r, value);
    }

protected:
    static constexpr int left(int v) { return v * 2 + 1; }
    static constexpr int right(int v) { return v * 2 + 2; }
    void build(const std::vector<T>& array, int v, int tl, int tr) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            tree[v] = array[tl];
        } else {
            const int tm = (tl + tr) / 2;
            build(array, left(v), tl, tm);
            build(array, right(v), tm, tr);
        }
    }
    T query(int v, int tl, int tr, int index) {
        if (tr - tl <= 0) {
            return query_id;
        }
        update_lazy(v);
        if (tr - tl == 1) {
            return tree[v];
        }
        const int tm = (tl + tr) / 2;
        if (index < tm) {
            return query(left(v), tl, tm, index);
        } else {
            return query(right(v), tm, tr, index);;
        }
    }
    void update(int v, int tl, int tr, int l, int r, const E& value) {
        if (l >= r) return;
        update_lazy(v);
        if (l == tl && r == tr) {
            lazy[v] = lazy_op(lazy[v], value);
            tree[v] = update_op(tree[v], value);
        } else {
            const int tm = (tl + tr) / 2;
            update(left(v), tl, tm, l, std::min(r,tm), value);
            update(right(v), tm, tr, std::max(l,tm), r, value);
        }
    }
    void update_lazy(int v) {
        if (left(v) < M) {
            lazy[left(v)] = lazy_op(lazy[left(v)], lazy[v]);
            tree[left(v)] = update_op(tree[left(v)], lazy[v]);
        }
        if (right(v) < M) {
            lazy[right(v)] = lazy_op(lazy[right(v)], lazy[v]);
            tree[right(v)] = update_op(tree[right(v)], lazy[v]);
        }
        lazy[v] = lazy_id;
    }
};