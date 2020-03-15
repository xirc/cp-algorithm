#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B

#include <vector>
#include <algorithm>
#include <functional>

// SegmentTree (PointUpdate,RangeQuery)
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

protected:
    F query_op;
    T query_id;
    G update_op;
    int N, M;
    std::vector<T> tree;

public:
    // O(N)
    SegmentTree(
        int n,
        const F& query_op, const T& query_id,
        const G& update_op
    )
        : query_op(query_op)
        , query_id(query_id)
        , update_op(update_op)
    {
        build(std::vector<T>(n, query_id));
    }
    // O(N)
    template <class Query, class Update>
    SegmentTree(int n, const Query& query, const Update& update)
        : SegmentTree(
            n,
            std::bind(&Query::operator(), query, std::placeholders::_1, std::placeholders::_2),
            query.id,
            std::bind(&Update::operator(), update, std::placeholders::_1, std::placeholders::_2)
        )
    {
        // Do nothing
    }
    // O(1)
    int size() {
        return N;
    }
    // O(N)
    void build(const std::vector<T>& array) {
        N = array.size();
        M = 4 * N;
        tree.assign(M, query_id);
        build(array, 0, 0, N);
    }
    // find the value in range [l, r)
    // O(log N)
    T query(int l, int r) {
        return query(0, 0, N, std::max(l,0), std::min(r,N));
    }
    // update the value at index = [0, n)
    // O(log N)
    bool update(int index, const E& value) {
        if (index < 0 || index >= N) {
            return false;
        }
        update(0, 0, N, index, value);
        return true;
    }
    // O(N logN)
    void dump(std::vector<T>& buffer) {
        buffer.clear();
        for (int i = 0; i < N; ++i) {
            buffer.push_back(query(i,i+1));
        }
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
            const int vl = left(v), vr = right(v);
            build(array, vl, tl, tm);
            build(array, vr, tm, tr);
            tree[v] = query_op(tree[vl], tree[vr]);
        }
    }
    T query(int v, int tl, int tr, int l, int r) {
        if (l >= r) {
            return query_id;
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        const int tm = (tl + tr) / 2;
        const int vl = left(v), vr = right(v);
        const auto sl = query(vl, tl, tm, l, std::min(r,tm));
        const auto sr = query(vr, tm, tr, std::max(l,tm), r);
        return query_op(sl, sr);
    }
    void update(int v, int tl, int tr, int index, const E& value) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            tree[v] = update_op(tree[v], value);
        } else {
            const int tm = (tl + tr) / 2;
            const int vl = left(v), vr = right(v);
            if (index < tm) {
                update(vl, tl, tm, index, value);
            } else {
                update(vr, tm, tr, index, value);
            }
            tree[v] = query_op(tree[vl], tree[vr]);
        }
    }
};