#pragma once

#include <random>
#include <vector>

template <class T>
class TreapBase {
protected:
    struct Node {
        T key;
        int priority;
        Node *left, *right;
        Node(T key, int priority)
            : key(key)
            , priority(priority)
            , left(nullptr)
            , right(nullptr)
            {
                // Do nothing
            }
    };
    using Tree = Node*;

    std::mt19937 random;
    Tree root = nullptr;

public:
    // O(logN)
    void insert(T key) {
        insert(root, new Node(key, random()));
    }
    // O(logN)
    bool erase(T key) {
        return erase(root, key);
    }
    // O(logN)
    bool find(T key) {
        return find(root, key);
    }
    // O(N)
    void dump(std::vector<T>& buffer) {
        buffer.clear();
        dump(root, buffer);
    }

protected:
    virtual void pushup(Tree tree) {
        // Do pushup procedure.
    }
    virtual void pushdown(Tree tree) {
        // Do pushdown procedure.
    }
    // O(logN)
    // left: <= key, right: > key
    void split(Tree tree, T key, Tree& left, Tree& right) {
        if (!tree) {
            left = right = nullptr;
            return;
        }
        pushdown(tree);
        if (key < tree->key) {
            split(tree->left, key, left, tree->left);
            right = tree;
        } else {
            split(tree->right, key, tree->right, right);
            left = tree;
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
        if (tree->key == key) {
            merge(tree, tree->left, tree->right);
            has_key = true;
        } else {
            has_key = erase(key < tree->key ? tree->left : tree->right, key);
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
        if (tree->key == key) {
            return true;
        } else {
            return find(key < tree->key ? tree->left : tree->right, key);
        }
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
};