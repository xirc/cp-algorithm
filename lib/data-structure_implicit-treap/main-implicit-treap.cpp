#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>
#include <cstdint>
#include "implicit-treap.hpp"
#include "../template-main.hpp"

using namespace std;

struct Data {
    int value, min, lazy;
    Data() {}
    Data(int value): value(value), min(INT_MAX), lazy(0) {}
};

class ImplicitTreap : public ImplicitTreapBase<Data> {
public:
    void add(int l, int r, int value) {
        add(root, l, r, value);
    }
    bool min(int l, int r, int& value) {
        return min(root, l, r, value);
    }

protected:
    void pushdown(Tree tree) override {
        if (!tree) {
            return;
        }
        if (tree->value.lazy) {
            const int lazy = tree->value.lazy;
            tree->value.lazy = 0;
            if (tree->left) {
                tree->left->value.value += lazy;
                tree->left->value.lazy += lazy;
                tree->left->value.min += lazy;
            }
            if (tree->right) {
                tree->right->value.value += lazy;
                tree->right->value.lazy += lazy;
                tree->right->value.min += lazy;
            }
        }
        ImplicitTreapBase::pushdown(tree);
    }
    void pushup(Tree tree) override {
        ImplicitTreapBase::pushup(tree);
        update_min(tree);
    }
    int min(Tree tree) {
        return tree ? tree->value.min : INT_MAX;
    }
    void update_min(Tree tree) {
        if (tree) {
            tree->value.min =
            std::min(
                tree->value.value, 
                std::min(min(tree->left), min(tree->right))
            );
        }
    }
    void add(Tree &tree, int l, int r, int x) {
        Tree t1, t2, t3;
        split(tree, l, t1, t2);
        split(t2, r - l, t2, t3);
        if (t2) {
            t2->value.value += x;
            t2->value.lazy += x;
            t2->value.min += x;
        }
        merge(t2, t2, t3);
        merge(tree, t1, t2);
    }
    bool min(Tree tree, int l, int r, int& value) {
        Tree t1, t2, t3;
        bool has_value = false;
        split(tree, l, t1, t2);
        split(t2, r - l, t2, t3);
        if (t2) {
            has_value = true;
            value = t2->value.min;
        }
        merge(t2, t2, t3);
        merge(tree, t1, t2);
        return has_value;
    }
};

ImplicitTreap itreap;
vector<Data> buffer;

void action_insert() {
    int pos, value;
    cin >> pos >> value;
    itreap.insert(pos, Data { value, });
}

void action_add() {
    int l, r, value;
    cin >> l >> r >> value;
    itreap.add(l, r, value);
}

void action_min() {
    int l, r, value;
    cin >> l >> r;
    bool ans = itreap.min(l, r, value);
    if (ans) {
        cout << value << endl;
    }
}

void action_erase() {
    int pos;
    cin >> pos;
    int ans = itreap.erase(pos);
    cout << (ans ? "true" : "false") << endl;
}

void action_at() {
    int pos, value;
    cin >> pos;
    if (pos < 0 || pos >= itreap.size()) {
        return;
    }
    cout << itreap.at(pos).value << endl;
}

void action_reverse() {
    int l, r;
    cin >> l >> r;
    itreap.reverse(l, r);
}

void action_rotate() {
    int l, m, r;
    cin >> l >> m >> r;
    itreap.rotate(l, m, r);
}

void action_count() {
    int l, r;
    cin >> l >> r;
    int ans = itreap.count(l, r);
    cout << ans << endl;
}

void action_dump() {
    itreap.dump(buffer);
    for (auto it = buffer.begin(); it != buffer.end(); it++) {
        if (it != buffer.begin()) cout << " ";
        cout << it->value;
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    commands["insert"] =
        Command { "insert {pos} {value}", action_insert };
    commands["add"] =
        Command { "add {left} {right} {value}", action_add };
    commands["min"] =
        Command { "min {left} {right}", action_min };
    commands["erase"] =
        Command { "erase {pos}", action_erase };
    commands["at"] =
        Command { "at {pos}", action_at };
    commands["reverse"] =
        Command { "reverse {left} {right}", action_reverse };
    commands["rotate"] =
        Command { "rotate {left} {middle} {right}", action_rotate };
    commands["count"] =
        Command { "count {left} {right}", action_count };
    commands["dump"] =
        Command { "dump", action_dump };
}