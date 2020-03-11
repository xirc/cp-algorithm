// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508

#include <cmath>
#include <random>
#include <vector>

template <class T>
class ImplicitTreapBase {
protected:
    struct Node {
        T value;
        int priority;
        int count;
        bool reverse;
        Node *left, *right;
        Node(T value, int priority)
            : value(value)
            , priority(priority)
            , count(0)
            , reverse(false)
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
    // O(1)
    int size() {
        return count(root);
    }
    // O(logN)
    void insert(int pos, T value) {
        insert(root, pos, new Node(value, random()));
    }
    // O(logN)
    T at(int pos) {
        T value;
        if (!at(root, pos, value)) throw;
        return value;
    }
    // O(logN)
    bool erase(int pos) {
        return erase(root, pos);
    }
    // O(logN)
    void reverse(int l, int r) {
        reverse(root, l, r);
    }
    // O(logN)
    void rotate(int l, int m, int r) {
        rotate(root, l, m, r);
    }
    // O(logN)
    int count(int l, int r) {
        return count(root, l, r);
    }
    // O(N)
    void dump(std::vector<T>& buffer) {
        buffer.clear();
        dump(root, buffer);
    }

protected:
    virtual void pushdown(Tree tree) {
        // Do pushdown procedure.
        if (!tree) {
            return;
        }
        if (tree->reverse) {
            tree->reverse = false;
            std::swap(tree->left, tree->right);
            if (tree->left) {
                tree->left->reverse ^= true;
            }
            if (tree->right) {
                tree->right->reverse ^= true;
            }
        }
    }
    virtual void pushup(Tree tree) {
        // Do pushup procedure.
        update_count(tree);
    }
    int count(Tree tree) {
        return tree ? tree->count : 0;
    }
    void update_count(Tree tree) {
        if (tree) {
            tree->count = 1 + count(tree->left) + count(tree->right);
        }
    }
    // O(logN)
    // left > key, right >= key
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
    // reverse elements in [l,r)
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
    void rotate(Tree tree, int l, int m, int r) {
        reverse(tree, l, r);
        reverse(tree, l, l + r - m);
        reverse(tree, l + r - m, r);
    }
    // O(logN)
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

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

struct Data {
    int value, minimum;
    bool active;
    Data(int value) : value(value), minimum(0), active(false) {}
};
class ImplicitTreap : public ImplicitTreapBase<Data> {
public:
    // [l,r)
    void update(int l, int r, int x) {
        Tree t1, t2, t3;
        split(root, l, t1, t2);
        split(t2, r - l, t2, t3);
        if (t2) {
            t2->value.value = x;
            t2->value.minimum = x;
            t2->value.active = true;
        }
        merge(t2, t2, t3);
        merge(root, t1, t2);
    }
    // [l,r)
    int minimum(int l, int r) {
        Tree t1, t2, t3;
        int ans;
        split(root, l, t1, t2);
        split(t2, r - l, t2, t3);
        ans = minimum(t2);
        merge(t2, t2, t3);
        merge(root, t1, t2);
        return ans;
    }
protected:
    int minimum(Tree tree) {
        return tree ? tree->value.minimum : numeric_limits<int>::max();
    }
    void pushdown(Tree tree) override {
        if (tree && tree->value.active) {
            tree->value.active = false;
            auto value = tree->value.value;
            auto& left = tree->left; auto& right = tree->right;
            if (left) {
                left->value.value = value;
                left->value.minimum = value;
                left->value.active = true;
            }
            if (right) {
                right->value.value = value;
                right->value.minimum = value;
                right->value.active = true;
            }
        }
        ImplicitTreapBase::pushdown(tree);
        pushup(tree);
    }
    void pushup(Tree tree) override {
        ImplicitTreapBase::pushup(tree);
        if (tree) {
            tree->value.minimum = std::min({ tree->value.value, minimum(tree->left), minimum(tree->right) });
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    ImplicitTreap treap;

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        treap.insert(i, Data(x));
    }

    for (int i = 0; i < Q; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0) {
            treap.rotate(y, z, z+1);
        } else if (x == 1) {
            cout << treap.minimum(y, z+1) << endl;
        } else if (x == 2) {
            treap.update(y, y+1, z);
        }
    }

    return 0;
}