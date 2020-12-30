#include <bits/stdc++.h>
#include "cpalgo/ds/union-find-tree-generic.hpp"
#include "template/template-main.hpp"

using namespace std;


struct Value {
    bool parity, bipartite;
    Value(size_t i): parity(false), bipartite(true) {}
    static void compress(Value& node, Value const& leader) {
        node.parity ^= leader.parity;
        node.bipartite = leader.bipartite;
    }
    static void unite_same(Value& leader, Value const& u, Value const& v, bool const& w) {
        if (u.parity == v.parity) {
            leader.bipartite = false;
        }
    }
    static void unite_diff(Value& leader, Value& follower, Value const& u, Value const& v, bool const& w) {
        follower.parity = u.parity ^ v.parity ^ true;
        leader.bipartite &= v.bipartite;
    }
};
UnionFindTree<Value, bool> tree;


string to_string(UnionFindTree<Value, bool>::node node) {
    return "(" + to_string(node.leader) + "," + to_string(node.value.bipartite) + ")";
}

void action_init() {
    size_t size;
    cin >> size;
    tree = UnionFindTree<Value, bool>(size);
    cout << "true" << endl;
}

void action_find() {
    size_t index;
    cin >> index;
    if (index >= tree.size()) {
        cout << "false" << endl;
        return;
    }
    auto ans = tree.find(index);
    cout << to_string(ans) << endl;
}

void action_unite() {
    size_t index1, index2;
    cin >> index1 >> index2;
    if (index1 >= tree.size()) {
        cout << "false" << endl;
        return;
    }
    if (index2 >= tree.size()) {
        cout << "false" << endl;
        return;
    }
    tree.unite(index1, index2, true);
    cout << "true" << endl;
}

void action_dump() {
    for (size_t i = 0; i < tree.size(); ++i) {
        if (i > 0) cout << " ";
        auto value = tree.find(i);
        cout << to_string(value);
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Bipartite Check using Union Find Tree";
    commands["init"] = Command { "init {size}", action_init };
    commands["find"] = Command { "find {index}", action_find };
    commands["unite"] = Command { "unite {index1} {index2}", action_unite };
    commands["dump"] = Command { "dump", action_dump };
}