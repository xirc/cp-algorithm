#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508

#include <vector>
#include <functional>
#include <cmath>
#include <random>
#include <memory>

template <class T, class E>
class ImplicitTreap {
public:
    using value_type_T = T;
    using value_type_E = E;
    using F = std::function<T(const T&, const T&, const T&)>;
    using G = std::function<T(const T&, const E&)>;
    using H = std::function<E(const E&, const E&)>;

protected:
    struct Node {
        using Tree = std::shared_ptr<Node>;
        T value;
        E lazy;
        int priority;
        int count;
        bool reverse;
        Tree left, right;
        Node(T value, E lazy, int priority)
            : value(value)
            , lazy(lazy)
            , priority(priority)
            , count(0)
            , reverse(false)
            , left(nullptr)
            , right(nullptr)
            {
                // Do nothing
            }
    };
    using Tree = std::shared_ptr<Node>;

    F query_op;
    T query_id;
    G update_op;
    H lazy_op;
    E lazy_id;

    std::mt19937 random;
    Tree root;

public:
    // O(1)
    ImplicitTreap(
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
        , random()
        , root(nullptr)
    {
        // Do nothing
    }
    // O(1)
    template <class Query, class Update, class Lazy>
    ImplicitTreap(
        const Query& query,
        const Update& update,
        const Lazy& lazy
    )
        : ImplicitTreap(
            std::bind(&Query::operator(), query, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
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
        return count(root);
    }
    // O(logN)
    void insert(int key, const T& value) {
        insert(root, key, Tree(new Node(value, lazy_id, random())));
    }
    // O(logN)
    T operator[](int key) {
        T value;
        if (!at(root, key, value)) {
            insert(key, query_id);
        }
        return at(key);
    }
    // O(logN)
    T at(int key) {
        T value;
        if (!at(root, key, value)) throw;
        return value;
    }
    // O(logN)
    bool erase(int key) {
        return erase(root, key);
    }
    // O(logN)
    // [l,r)
    bool query(int l, int r, T& value) {
        return query(root, l, r, value);
    }
    // O(logN)
    // [,r)
    T query(int l, int r) {
        T value;
        bool has_value = query(root, l, r, value);
        return has_value ? value : query_id;
    }
    // O(logN)
    // [l,r)
    bool update(int l, int r, const E& value) {
        return update(root, l, r, value);
    }
    // O(logN)
    // [l,r)
    void reverse(int l, int r) {
        reverse(root, l, r);
    }
    // O(logN)
    // [l,m,r)
    // rotate left +1 = rotate(tree, l, l+1, r)
    // rotate right +1 = rotate(tree, l, r-1, r)
    void rotate(int l, int m, int r) {
        rotate(root, l, m, r);
    }
    // O(logN)
    // [l,r)
    int count(int l, int r) {
        return count(root, l, r);
    }
    // O(N)
    void dump(std::vector<T>& buffer) {
        buffer.clear();
        dump(root, buffer);
    }

protected:
    // O(1)
    void pushdown(Tree tree) {
        if (tree && tree->reverse) {
            tree->reverse = false;
            std::swap(tree->left, tree->right);
            if (tree->left) {
                tree->left->reverse ^= true;
            }
            if (tree->right) {
                tree->right->reverse ^= true;
            }
        }
        pushdown_value(tree);
    }
    // O(1)
    void pushdown_value(Tree tree) {
        if (tree) {
            if (tree->left) {
                tree->left->value = update_op(tree->left->value, tree->lazy);
                tree->left->lazy = lazy_op(tree->left->lazy, tree->lazy);
            }
            if (tree->right) {
                tree->right->value = update_op(tree->right->value, tree->lazy);
                tree->right->lazy = lazy_op(tree->right->lazy, tree->lazy);
            }
            tree->lazy = lazy_id;
        }
    }
    // O(1)
    void pushup(Tree tree) {
        update_count(tree);
        pushup_value(tree);
    }
    // O(1)
    void pushup_value(Tree tree) {
        if (tree) {
            auto lvalue = tree->left ? tree->left->value : query_id;
            auto rvalue = tree->right ? tree->right->value : query_id;
            tree->value = query_op(tree->value, lvalue, rvalue);
        }
    }
    // O(1)
    int count(Tree tree) {
        return tree ? tree->count : 0;
    }
    // O(1)
    void update_count(Tree tree) {
        if (tree) {
            tree->count = 1 + count(tree->left) + count(tree->right);
        }
    }
    // O(logN)
    // left: < key, right: >= key
    void split(Tree tree, int key, Tree &left, Tree &right) {
        if (!tree) {
            left = right = nullptr;
            return;
        }
        pushdown(tree);
        const int implicit_key = count(tree->left) + 1;
        if (key < implicit_key) {
            split(tree->left, key, left, tree->left);
            right = tree;
        } else {
            split(tree->right, key - implicit_key, tree->right, right);
            left = tree;
        }
        pushup(tree);
    }
    // O(logN)
    void merge(Tree& tree, Tree left, Tree right) {
        pushdown(left);
        pushdown(right);
        if (!left || !right) {
            tree = left ? left : right;
        } else if (left->priority > right->priority) {
            merge(left->right, left->right, right);
            tree = left;
        } else {
            merge(right->left, left, right->left);
            tree = right;
        }
        pushup(tree);
    }
    // O(logN)
    void insert(Tree& tree, int key, Tree item) {
        Tree t1, t2;
        split(tree, key, t1, t2);
        merge(t1, t1, item);
        merge(tree, t1, t2);
    }
    // O(logN)
    bool erase(Tree& tree, int key) {
        Tree t1, t2, t3;
        split(tree, key + 1, t1, t2);
        split(t1, key, t1, t3);
        merge(tree, t1, t2);
        return t3 != nullptr;
    }
    // O(logN)
    bool at(Tree &tree, int key, T& value) {
        Tree t1, t2, t3;
        bool has_value = false;
        split(tree, key, t1, t2);
        split(t2, 1, t2, t3);
        if (t2) {
            has_value = true;
            value = t2->value;
        }
        merge(t2, t2, t3);
        merge(tree, t1, t2);
        return has_value;
    }
    // O(logN)
    // [l,r)
    bool query(Tree tree, int l, int r, T& value) {
        Tree t1, t2, t3;
        bool has_value = false;
        split(tree, l, t1, t2);
        split(t2, r - l, t2, t3);
        if (t2) {
            has_value = true;
            value = t2->value;
        }
        merge(t2, t2, t3);
        merge(tree, t1, t2);
        return has_value;
    }
    // O(logN)
    // [l,r)
    bool update(Tree &tree, int l, int r, const E& value) {
        bool has_value = false;
        Tree t1, t2, t3;
        split(tree, l, t1, t2);
        split(t2, r - l, t2, t3);
        if (t2) {
            has_value = true;
            t2->value = update_op(t2->value, value);
            t2->lazy = lazy_op(t2->lazy, value);
        }
        merge(t2, t2, t3);
        merge(tree, t1, t2);
        return has_value;
    }
    // O(logN)
    // [l,r)
    void reverse(Tree tree, int l, int r) {
        if (l > r) {
            return;
        }
        Tree t1, t2, t3;
        split(tree, l, t1, t2);
        split(t2, r - l, t2, t3);
        t2->reverse ^= true;
        merge(t2, t2, t3);
        merge(tree, t1, t2);
    }
    // O(logN)
    // [l,m,r)
    void rotate(Tree tree, int l, int m, int r) {
        reverse(tree, l, r);
        reverse(tree, l, l + r - m);
        reverse(tree, l + r - m, r);
    }
    // O(logN)
    // [l,r)
    int count(Tree tree, int l, int r) {
        Tree t1, t2, t3;
        int ans;
        split(tree, l, t1, t2);
        split(t2, r - l, t2, t3);
        ans = count(t2);
        merge(t2, t2, t3);
        merge(tree, t1, t2);
        return ans;
    }
    // O(N)
    void dump(Tree tree, std::vector<T>& buffer) {
        if (!tree) {
            return;
        }
        pushdown(tree);
        dump(tree->left, buffer);
        buffer.push_back(tree->value);
        dump(tree->right, buffer);
    }
};