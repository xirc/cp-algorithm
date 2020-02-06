// https://www.spoj.com/problems/TWIST/

#include <iostream>
#include <random>
#include <vector>

using namespace std;

class ImplicitTreap {
    struct Node {
        int value;
        int priority;
        int count;
        bool reverse;
        Node *left, *right;
        Node(int value, int priority)
            : value(value)
            , priority(priority)
            , count(0)
            , reverse(false)
            , left(nullptr)
            , right(nullptr)
        {}
    };
    using Tree = Node*;

    std::random_device random;
    Tree root;

public:
    void insert(int pos, int value) {
        insert(root, pos, new Node(value, random()));
    }
    void reverse(int l, int r) {
        reverse(root, l, r);
    }
    void dump(vector<int>& buffer){
        buffer.clear();
        dump(root, buffer);
    }

private:
    void pushdown(Tree tree) {
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
        pushup(tree);
    }
    void pushup(Tree tree) {
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
    void split(Tree tree, int key, Tree& left, Tree& right) {
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
    void insert(Tree &tree, int key, Tree item) {
        Tree t1, t2;
        split(tree, key, t1, t2);
        merge(t1, t1, item);
        merge(tree, t1, t2);
    }
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
    void dump(Tree tree, vector<int>& buffer) {
        if (!tree) {
            return;
        }
        pushdown(tree);
        dump(tree->left, buffer);
        buffer.push_back(tree->value);
        dump(tree->right, buffer);
    }
};

int N, M;
vector<int> ans;
ImplicitTreap treap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        treap.insert(i, i + 1);
    }
    for (int i = 0; i < M; ++i) {
        int p, q;
        cin >> p >> q;
        p--, q--;
        treap.reverse(p, q+1);
    }
    treap.dump(ans);

    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}