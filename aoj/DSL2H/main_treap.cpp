// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H

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

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

struct Data {
    int index;
    long long value, lazy, minimum;
    bool operator<(const Data& other) {
        return index < other.index;
    }
};
class Treap : public TreapBase<Data> {
public:
    // [l,r)
    void add(int l, int r, long long x) {
        Tree t1, t2, t3;
        split(root, { l - 1, 0, 0, 0 }, t1, t2);
        split(t2, { r - 1, 0, 0, 0 }, t2, t3);
        if (t2) {
            t2->key.value += x;
            t2->key.lazy += x;
            t2->key.minimum += x;
        }
        merge(t2, t2, t3);
        merge(root, t1, t2);
    }
    // [l,r)
    long long minimum(int l, int r) {
        Tree t1, t2, t3;
        long long ans;
        split(root, { l - 1, 0, 0, 0 }, t1, t2);
        split(t2, { r - 1, 0, 0, 0 }, t2, t3);
        ans = minimum(t2);
        merge(t2, t2, t3);
        merge(root, t1, t2);
        return ans;
    }
protected:
    long long minimum(Tree node) {
        return node ? node->key.minimum : numeric_limits<long long>::max();
    }
    void pushup(Tree node) override {
        if (!node) return;

        node->key.minimum = min({ node->key.value, minimum(node->left), minimum(node->right) });
    }
    void pushdown(Tree node) override {
        if (!node) return;

        auto lazy = node->key.lazy;
        auto& left = node->left;
        auto& right = node->right;
        if (left) {
            left->key.value += lazy;
            left->key.lazy += lazy;
            left->key.minimum += lazy;
        }
        if (right) {
            right->key.value += lazy;
            right->key.lazy += lazy;
            right->key.minimum += lazy;
        }
        node->key.lazy = 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    Treap treap;
    for (int i = 0; i < N; ++i) {
        treap.insert({ i, 0, 0, 0 });
    }

    for (int i = 0; i < Q; ++i) {
        int c, s, t, x;
        cin >> c;
        if (c == 0 ) {
            cin >> s >> t >> x;
            treap.add(s, t+1, x);
        } else if (c == 1) {
            cin >> s >> t;
            cout << treap.minimum(s, t+1) << endl;
        } else throw;
    }

    return 0;
}