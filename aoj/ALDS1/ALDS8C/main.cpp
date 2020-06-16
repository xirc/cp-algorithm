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
    void erase(int value) {
        erase(root, value);
    }
    bool find(int value) {
        return find(root, value);
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
    void erase(Tree& node, int value) {
        if (node == nullptr) {
            return;
        }
        if (value < node->value) {
            erase(node->left, value);
        } else if (value > node->value) {
            erase(node->right, value);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                Node* tmp = node;
                node = node->right;
                delete tmp;
            } else if (node->right == nullptr) {
                Node* tmp = node;
                node = node->left;
                delete tmp;
            } else {
                Tree& successor = next_inorder(node->right);
                node->value = successor->value;
                erase(successor, successor->value);
            }
        }
    }
    Tree& next_inorder(Tree& node) {
        if (node == nullptr) return node;
        if (node->left != nullptr) return next_inorder(node->left);
        return node;
    }
    bool find(const Tree& node, int value){
        if (node == nullptr) return false;
        if (value == node->value) return true;
        if (value < node->value) {
            return find(node->left, value);
        } else {
            return find(node->right, value);
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
            int value;
        cin >> cmd;
        if (cmd == "insert") {
            cin >> value;
            tree.insert(value);
        } else if (cmd == "delete") {
            cin >> value;
            tree.erase(value);
        } else if (cmd == "find") {
            cin >> value;
            auto found = tree.find(value);
            cout << (found ? "yes" : "no") << endl;
        } else if (cmd == "print") {
            tree.print();
        } else throw;
    }

    return 0;
}