#include <bits/stdc++.h>

using namespace std;

class Treap {
    struct Node {
        int value;
        int priority;
        Node *left, *right;
        Node(int value, int priority)
            : value(value)
            , priority(priority)
            , left(nullptr)
            , right(nullptr)
        {
            // Do nothing
        }
    };
    Node* root = nullptr;

public:
    void insert(int value, int priority) {
        root = insert(root, value, priority);
    }
    void erase(int value) {
        root = erase(root, value);
    }
    bool find(int value) {
        return find(root, value);
    }
    void print() {
        print_inorder(root);
        cout << endl;
        print_preorde(root);
        cout << endl;
    }

private:
    Node* rightRotate(Node* node) {
         auto r = node->left;
         node->left = r->right;
         r->right = node;
         return r;
    }
    Node* leftRotate(Node* node) {
        auto r = node->right;
        node->right = r->left;
        r->left = node;
        return r;
    }
    Node* insert(Node* node, int value, int priority) {
        if (node == nullptr) {
            return new Node(value, priority);
        }
        if (value == node->value) {
            return node;
        }
        if (value < node->value) {
            node->left = insert(node->left, value, priority);
            if (node->priority < node->left->priority) {
                node = rightRotate(node);
            }
        } else {
            node->right = insert(node->right, value, priority);
            if (node->priority < node->right->priority) {
                node = leftRotate(node);
            }
        }
        return node;
    }
    Node* erase(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->value) {
            node->left = erase(node->left, value);
            return node;
        } else if (value > node->value) {
            node->right = erase(node->right, value);
            return node;
        } else {
            return erase_just(node, value);
        }
    }
    Node* erase_just(Node* node, int value) {
        if (node->value != value) throw;
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        if (node->left == nullptr) {
            node = leftRotate(node);
        } else if (node->right == nullptr) {
            node = rightRotate(node);
        } else {
            if (node->left->priority > node->right->priority) {
                node = rightRotate(node);
            } else {
                node = leftRotate(node);
            }
        }
        return erase(node, value);
    }
    bool find(const Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (value < node->value) {
            return find(node->left, value);
        } else if (value > node->value) {
            return find(node->right, value);
        } else {
            return true;
        }
    }
    void print_inorder(const Node* node) {
        if (node == nullptr) return;
        print_inorder(node->left);
        cout << " " << node->value;
        print_inorder(node->right);
    }
    void print_preorde(const Node* node) {
        if (node == nullptr) return;
        cout << " " << node->value;
        print_preorde(node->left);
        print_preorde(node->right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Treap treap;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string cmd;
        int value, priority;
        cin >> cmd;
        if (cmd == "insert") {
            cin >> value >> priority;
            treap.insert(value, priority);
        } else if (cmd == "delete") {
            cin >> value;
            treap.erase(value);
        } else if (cmd == "find") {
            cin >> value;
            auto found = treap.find(value);
            cout << (found ? "yes" : "no") << endl;
        } else if (cmd == "print") {
            treap.print();
        } else throw;
    }

    return 0;
}