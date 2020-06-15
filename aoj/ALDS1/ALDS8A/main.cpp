#include <bits/stdc++.h>

using namespace std;

class BinarySearchTree {
    struct Node {
        int value;
        Node *left, *right;
        Node(int value)
            : value(value)
            , left(nullptr)
            , right(nullptr)
        {
            // Do nothing
        }
    };
    using Tree = Node*;
    Tree root = nullptr;

public:
    void insert(int value) {
        insert(root, value);
    }
    void print() {
        print_inorder(root);
        cout << endl;
        print_preorder(root);
        cout << endl;
    }

private:
    void insert(Tree& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
            return;
        }
        if (value < node->value) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }
    void print_inorder(Tree& node) {
        if (node == nullptr) return;
        print_inorder(node->left);
        cout << " " << node->value;
        print_inorder(node->right);
    }
    void print_preorder(Tree& node) {
        if (node == nullptr) return;
        cout << " " << node->value;
        print_preorder(node->left);
        print_preorder(node->right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    BinarySearchTree tree;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            int value;
            cin >> value;
            tree.insert(value);
        } else if (cmd == "print") {
            tree.print();
        } else throw;
    }

    return 0;
}