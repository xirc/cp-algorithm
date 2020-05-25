#pragma once

#include <memory>
#include <random>
#include <functional>

// Heap (Randomized Heap)
// Memory: O(N)
// NOTE: You can merge other Heap which has same update operator.
template <class T, class E = T, class less = std::less<T>>
class Heap {
public:
    using value_type_T = T;
    using value_type_E = E;
    using G = std::function<T(const T&, const E&)>;
    using H = std::function<E(const E&, const E&)>;

protected:
    struct node {
        using tree = std::shared_ptr<node>;
        T value;
        E lazy;
        tree left;
        tree right;
        node(T value, E lazy)
            : value(value)
            , lazy(lazy)
            , left(nullptr)
            , right(nullptr) {}
    };
    using tree = std::shared_ptr<node>;

    tree root = nullptr;
    std::mt19937 random;
    less op;

    G update_op;
    H lazy_op;
    E lazy_id;

public:
    Heap(
        G update_op = [&](const T& l, const E& r) { return l + r; },
        H lazy_op = [&](const E& l, const E& r) { return l + r; },
        E lazy_id = E()
    )
        : update_op(update_op)
        , lazy_op(lazy_op)
        , lazy_id(lazy_id)
    {
        // Do nothing
    }
    // O(logN)
    bool empty() {
        return root == nullptr;
    }
    // O(logN)
    T top() {
        pushdown(root);
        return root->value;
    }
    // O(logN)
    void pop() {
        pushdown(root);
        root = merge(root->left, root->right);
    }
    // O(logN)
    void insert(T value) {
        root = merge(root, tree(new node(value, lazy_id)));
    }
    // O(logN)
    void merge(Heap<T,E,less>& other) {
        root = merge(root, other.root);
        other.root = nullptr;
    }
    // O(1)
    void update(E value) {
        if (root == nullptr) return;
        root->lazy =
            lazy_op(root->lazy, value);
    }

protected:
    // O(logN)
    tree merge(tree u, tree v) {
        if (u == nullptr || v == nullptr) {
            return u ? u : v;
        }
        pushdown(u);
        pushdown(v);
        if (op(v->value, u->value)) {
            std::swap(u, v);
        }
        if (random() & 1) {
            std::swap(u->left, u->right);
        }
        u->left = merge(u->left, v);
        return u;
    };
    // O(1)
    void pushdown(tree v) {
        if (v == nullptr) return;
        if (v->left != nullptr) {
            v->left->lazy =
                lazy_op(v->left->lazy, v->lazy);
        }
        if (v->right != nullptr) {
            v->right->lazy =
                lazy_op(v->right->lazy, v->lazy);
        }
        v->value = update_op(v->value, v->lazy);
        v->lazy = lazy_id;
    }
};