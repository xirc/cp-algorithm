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

    std::random_device random;
    Tree root = nullptr;

public:
    void insert(T key) {
        insert(root, new Node(key, random()));
    }

    bool erase(T key) {
        return erase(root, key);
    }

    bool find(T key) {
        return find(root, key);
    }

    int size() 
    {
        return count(root);
    }

    void dump(std::vector<T>& buffer) {
        buffer.clear();
        dump(root, buffer);
    }

protected:
    virtual void pushup(Tree tree) {
        // Do pushup procedure.
    }

    virtual void pushdown(Tree tree) {
        // Do pushdown procedure, and then finally pushup.
        pushup(tree);
    }

    void split(Tree tree, T key, Tree& left, Tree& right) {
        if (!tree) {
            left = right = nullptr;
            return;
        }
        pushdown(tree);
        if (key < tree->key) {
            split(tree->left, key, left, tree->right);
            right = tree;
        } else {
            split(tree->right, key, tree->right, right);
            left = tree;
        }
        pushup(tree);
    }

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