#pragma once

#include <memory>
#include <random>

// RandomizedHeap
// Memory: O(N)
template <class T, class less = std::less<T>>
class Heap {
    struct node {
        using tree = std::shared_ptr<node>;
        T value;
        tree left;
        tree right;
        node(T value): value(value), left(nullptr), right(nullptr) {}
    };
    using tree = std::shared_ptr<node>;
    tree root = nullptr;
    std::mt19937 random;
    less op;

public:
    // O(logN)
    bool empty() {
        return root == nullptr;
    }
    // O(logN)
    T top() {
        return root->value;
    }
    // O(logN)
    void pop() {
        root = merge(root->left, root->right);
    }
    // O(logN)
    void insert(T value) {
        root = merge(root, tree(new node(value)));
    }
    // O(logN)
    void merge(Heap& other) {
        root = merge(root, other.root);
        other.root = nullptr;
    }

protected:
    // O(logN)
    tree merge(tree u, tree v) {
        if (u == nullptr || v == nullptr) {
            return u ? u : v;
        }
        if (op(v->value, u->value)) {
            std::swap(u, v);
        }
        if (random() & 1) {
            std::swap(u->left, u->right);
        }
        u->left = merge(u->left, v);
        return u;
    };
};