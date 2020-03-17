#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H

#include <vector>
#include <functional>
#include <random>

template <class T, class E>
class Treap {
public:
    using F = std::function<T(const T&, const T&, const T&)>;
    using G = std::function<T(const T&, const E&)>;
    using H = std::function<E(const E&, const E&)>;

protected:
    struct Node {
        T key;
        E lazy;
        int priority;
        Node *left, *right;
        Node(T key, E lazy, int priority)
            : key(key)
            , lazy(lazy)
            , priority(priority)
            , left(nullptr)
            , right(nullptr)
            {
                // Do nothing
            }
    };
    using Tree = Node*;

    std::mt19937 random;
    Tree root;
    F query_op;
    T query_id;
    G update_op;
    H lazy_op;
    E lazy_id;

public:
    // O(1)
    Treap(
        const F& query_op,
        const T& query_id,
        const G& update_op,
        const H& lazy_op,
        const E& lazy_id
    )
        : root(nullptr)
        , random()
        , query_op(query_op)
        , query_id(query_id)
        , update_op(update_op)
        , lazy_op(lazy_op)
        , lazy_id(lazy_id)
    {
        // Do nothing
    }
    // O(1)
    template <class Query, class Update, class Lazy>
    Treap(const Query& query, const Update& update, const Lazy& lazy)
        : Treap(
            std::bind(&Query::operator(), query, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            query.id,
            std::bind(&Update::operator(), update, std::placeholders::_1, std::placeholders::_2),
            std::bind(&Lazy::operator(), lazy, std::placeholders::_1, std::placeholders::_2),
            lazy.id
        )
    {
        // Do nothing
    }
    // O(N)
    void dump(std::vector<T>& buffer) {
        buffer.clear();
        dump(root, buffer);
    }
    // O(logN)
    void insert(T key) {
        insert(root, new Node(key, lazy_id, random()));
    }
    // O(logN)
    bool erase(T key) {
        return erase(root, key);
    }
    // O(logN)
    bool find(T key) {
        return find(root, key);
    }
    // O(logN)
    T query(const T& l, const T& r) {
        return query(root, l, r);
    }
    // O(logN)
    bool update(const T& l, const T& r, const E& value) {
        return update(root, l, r, value);
    }

protected:
    void pushup(Tree tree) {
        if (tree) {
            auto lkey = tree->left ? tree->left->key : query_id;
            auto rkey = tree->right ? tree->right->key : query_id;
            tree->key = query_op(tree->key, lkey, rkey);
        }
    }
    void pushdown(Tree tree) {
        if (tree) {
            if (tree->left) {
                tree->left->key = update_op(tree->left->key, tree->lazy);
                tree->left->lazy = lazy_op(tree->left->lazy, tree->lazy);
            }
            if (tree->right) {
                tree->right->key = update_op(tree->right->key, tree->lazy);
                tree->right->lazy = lazy_op(tree->right->lazy, tree->lazy);
            }
            tree->lazy = lazy_id;
        }
    }
    // O(logN)
    // left: < key, right: >= key
    void split(Tree tree, T key, Tree& left, Tree& right) {
        if (!tree) {
            left = right = nullptr;
            return;
        }
        pushdown(tree);
        if (tree->key < key) {
            split(tree->right, key, tree->right, right);
            left = tree;
        } else {
            split(tree->left, key, left, tree->left);
            right = tree;
        }
        pushup(tree);
    }
    // O(logN)
    void merge(Tree &tree, Tree left, Tree right) {
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
    // O(N)
    void dump(Tree tree, std::vector<T>& buffer) {
        if (!tree) {
            return;
        }
        pushdown(tree);
        dump(tree->left, buffer);
        buffer.push_back(tree->key);
        dump(tree->right, buffer);
    }
    // O(logN)
    void insert(Tree &tree, Tree item) {
        if (!tree) {
            tree = item;
            return;
        }
        pushdown(tree);
        if (item->priority > tree->priority) {
            split(tree, item->key, item->left, item->right);
            tree = item;
        } else {
            insert(item->key < tree->key ? tree->left : tree->right, item);
        }
        pushup(tree);
    }
    // O(logN)
    bool erase(Tree &tree, T key) {
        if (!tree) {
            return false;
        }
        bool has_key;
        pushdown(tree);
        if (key < tree->key) {
            has_key = erase(tree->left, key);
        } else if (tree->key < key) {
            has_key = erase(tree->right, key);
        } else {
            merge(tree, tree->left, tree->right);
            has_key = true;
        }
        pushup(tree);
        return has_key;
    }
    // O(logN)
    bool find(Tree tree, T key) {
        if (!tree) {
            return false;
        }
        pushdown(tree);
        if (key < tree->key) {
            return find(tree->left, key);
        } else if (tree->key < key) {
            return find(tree->right, key);
        } else {
            return true;
        }
    }
    // O(logN)
    // [l,r)
    T query(Tree &tree, const T &l, const T& r) {
        Tree t1, t2, t3;
        T ans;
        split(tree, l, t1, t2);
        split(t2, r, t2, t3);
        ans = t2 ? t2->key : query_id;
        merge(t2, t2, t3);
        merge(tree, t1, t2);
        return ans;
    }
    // O(logN)
    // [l,r)
    bool update(Tree &tree, const T& l, const T& r, const E& value) {
        Tree t1, t2, t3;
        bool has_key = false;
        split(tree, l, t1, t2);
        split(t2, r, t2, t3);
        if (t2) {
            has_key = true;
            t2->key = update_op(t2->key, value);
            t2->lazy = lazy_op(t2->lazy, value);
        }
        merge(t2, t2, t3);
        merge(tree, t1, t2);
        return has_key;
    }
};