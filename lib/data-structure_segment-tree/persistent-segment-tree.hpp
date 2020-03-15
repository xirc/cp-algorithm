#pragma once

#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
#include <memory>

// PersistentSegmentTree (RangeUpdate,RangeQuery)
// Memory O(N * H)
// Build  O(N)
// Query O(log N)
// Update O(log N)
template <class T, class E>
class SegmentTree {
public:
    using value_type_T = T;
    using value_type_E = E;
    using F = std::function<T(const T&, const T&)>;
    using G = std::function<T(const T&, const E&)>;
    using H = std::function<E(const E&, const E&)>;

protected:
    struct vertex {
        using tree = std::shared_ptr<vertex>;
        T value;
        E lazy;
        tree left, right;
        vertex(const T& value, const E& lazy, const tree& left, const tree& right)
            : value(value), lazy(lazy), left(left), right(right)
        {}
    };
    using tree = std::shared_ptr<vertex>;

    F query_op;
    T query_id;
    G update_op;
    H lazy_op;
    E lazy_id;

    int N;
    std::deque<tree> history;

public:
    // O(N)
    SegmentTree(
        int n,
        const F& query_op, const T& query_id,
        const G& update_op,
        const H& lazy_op, const E& lazy_id
    )
        : query_op(query_op)
        , query_id(query_id)
        , update_op(update_op)
        , lazy_op(lazy_op)
        , lazy_id(lazy_id)
    {
        build(std::vector<T>(n,query_id));
    }
    // O(N)
    template <class Query, class Update, class Lazy>
    SegmentTree(int n, const Query& query, const Update& update, const Lazy& lazy)
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
    // O(1)
    int history_size() {
        return history.size();
    }
    // O(N)
    void build(const std::vector<T>& array) {
        N = array.size();
        history.clear();
        if (N == 0) {
            history.emplace_front(make_vertex());
        } else {
            const auto root = build(array, 0, N);
            history.emplace_front(root);
        }
    }
    // O(logN)
    // [l,r)
    T query(int l, int r, int index = 0) {
        if (index < 0 || index >= history.size()) {
            return query_id;
        }
        return query(history[index], l, r);
    }
    // O(logN)
    // [l,r)
    bool update(int l, int r, const E& value, int index = 0) {
        if (index < 0 || index >= history.size()) {
            return false;
        }
        for (int i = 0; i < index; ++i) history.pop_front();
        const auto root = update(history[0], l, r, value);
        history.emplace_front(root);
        return true;
    }
    // O(N logN)
    void dump(std::vector<T>& buffer, int hindex = 0) {
        buffer.resize(N);
        for (int i = 0; i < N; ++i) {
            buffer[i] = query(i, i + 1, hindex);
        }
    }
    // O(K)
    void drop_histroy(int index = 0) {
        if (index < 0 || index >= histroy.size()) throw;
        histroy.resize(index+1);
    }

protected:
    tree make_vertex() {
        return tree(new vertex(query_id, lazy_id, nullptr, nullptr));
    }
    tree make_vertex(const T& value) {
        return tree(new vertex(value, lazy_id, nullptr, nullptr));
    }
    tree make_vertex(const T& value, const E& lazy, const tree left, const tree right) {
        return tree(new vertex(value, lazy, left, right));
    }
    tree make_vertex(const tree left, const tree right) {
        auto lvalue = left ? left->value : query_id;
        auto rvalue = right ? right->value : query_id;
        auto value = query_op(lvalue, rvalue);
        return tree(new vertex(value, lazy_id, left, right));
    }
    tree build(const std::vector<T>& array, int tl, int tr) {
        if (tr - tl <= 0) return nullptr;
        if (tr - tl == 1) {
            return make_vertex(array[tl]);
        }
        const int tm = (tl + tr) / 2;
        const auto lhs = build(array, tl, tm);
        const auto rhs = build(array, tm, tr);
        return make_vertex(lhs, rhs);
    }
    T query(tree root, int l, int r) {
        return query(root, 0, N, std::max(l,0), std::min(r,N));
    }
    T query(tree v, int tl, int tr, int l, int r) {
        if (r - l <= 0) return query_id;
        update_lazy(v);
        if (l == tl && r == tr) {
            return v->value;
        } else {
            const int tm = (tl + tr) / 2;
            const T lhs = query(v->left, tl, tm, l, std::min(r,tm));
            const T rhs = query(v->right, tm, tr, std::max(l,tm), r);
            return query_op(lhs, rhs);
        }
    }
    tree update(tree root, int l, int r, const E& value) {
        return update(root, 0, N, std::max(l,0), std::min(r,N), value);
    }
    tree update(tree v, int tl, int tr, int l, int r, const E& value) {
        if (tr - tl <= 0) {
            return nullptr;
        }
        update_lazy(v);
        if (r <= tl || l >= tr) {
            return v;
        }
        if (tl == l && tr == r) {
            auto new_value = update_op(v->value, value);
            auto new_lazy = lazy_op(v->lazy, value);
            return make_vertex(new_value, new_lazy, v->left, v->right);
        }
        const int tm = (tl + tr) / 2;
        const auto left = update(v->left, tl, tm, l, std::min(r,tm), value);
        const auto right = update(v->right, tm, tr, std::max(l,tm), r, value);
        return make_vertex(left, right);
    }
    void update_lazy(tree v) {
        if (v->lazy == lazy_id) return;
        if (v->left) {
            auto new_value = update_op(v->left->value, v->lazy);
            auto new_lazy = lazy_op(v->left->lazy, v->lazy);
            v->left = make_vertex(new_value, new_lazy, v->left->left, v->left->right);
        }
        if (v->right) {
            auto new_value = update_op(v->right->value, v->lazy);
            auto new_lazy = lazy_op(v->right->lazy, v->lazy);
            v->right = make_vertex(new_value, new_lazy, v->right->left, v->right->right);
        }
        v->lazy = lazy_id;
    }
};