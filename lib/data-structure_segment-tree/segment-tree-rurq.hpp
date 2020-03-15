#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F

#include <vector>
#include <algorithm>
#include <functional>

// SegmentTree (RangeUpdate,RangeQuery)
// Memory O(N)
// Build  O(N)
// Query O(log N)
// Update O(log N)
template<class T, class E>
class SegmentTree {
public:
    using value_type_T = T;
    using value_type_E = E;
    using F = std::function<T(const T&, const T&)>;
    using G = std::function<T(const T&, const E&)>;
    using H = std::function<E(const E&, const E&)>;

protected:
    F query_op;
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
        const F& query_op,
        const T& query_id,
        const G& update_op,
        const H& lazy_op,
        const E& lazy_id
    )
        : query_op(query_op)
        , query_id(query_id)
        , update_op(update_op)
        , lazy_op(lazy_op)
        , lazy_id(lazy_id)
    {
        build(std::vector<T>(n, query_id));
    }
    // O(N)
    template <class Query, class Update, class Lazy>
    SegmentTree(int n, Query query, Update update, Lazy lazy)
        : SegmentTree(
            n,
            std::bind(&Query::operator(), query, std::placeholders::_1, std::placeholders::_2),
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
            buffer.push_back(query(i,i+1));
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
    // [l,r)
    T query(int l, int r) {
        return query(0, 0, N, std::max(l,0), std::min(r,N));
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
            tree[v] = query_op(tree[left(v)], tree[right(v)]);
        }
    }
    T query(int v, int tl, int tr, int l, int r) {
        if (l >= r) {
            return query_id;
        }
        update_lazy(v);
        if (l == tl && r == tr) {
            return tree[v];
        }
        const int tm = (tl + tr) / 2;
        const auto lhs = query(left(v), tl, tm, l, std::min(r,tm));
        const auto rhs = query(right(v), tm, tr, std::max(l,tm), r);
        return query_op(lhs, rhs);
    }
    void update(int v, int tl, int tr, int l, int r, const E& value) {
        if (l >= r) return;
        update_lazy(v);
        if (l == tl && r == tr) {
            lazy[v] = lazy_op(lazy[v], value);
            tree[v] = update_op(tree[v], value);
        } else {
            const int tm = (tl + tr) / 2;
            update(left(v), tl, tm, l, std::min(r, tm), value);
            update(right(v), tm, tr, std::max(l,tm), r, value);
            tree[v] = query_op(tree[left(v)], tree[right(v)]);
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