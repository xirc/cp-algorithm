#include <bits/stdc++.h>
#include "template/template-main.hpp"
#include "cpalgo/ds/union_find_tree.hpp"

using namespace std;

UnionFindTree tree;

string to_string(UnionFindTree::node value) {
    return to_string(value.leader);
}

void action_init() {
    size_t size;
    cin >> size;
    tree = UnionFindTree(size);
    cout << "true" << endl;
}

void action_find() {
    size_t v;
    cin >> v;
    if (v >= tree.size()) {
        cout << -1 << endl;
        return;
    }
    auto ans = tree.find(v);
    cout << to_string(ans) << endl;
}

void action_unite() {
    size_t u, v;
    cin >> u >> v;
    if (u >= tree.size()) {
        cout << "false" << endl;
        return;
    }
    if (v >= tree.size()) {
        cout << "false" << endl;
        return;
    }
    tree.unite(u, v);
    cout << "true" << endl;
}

void action_dump() {
    for (size_t i = 0; i < tree.size(); ++i) {
        if (i != 0) cout << " ";
        auto value = tree.find(i);
        cout << to_string(value);
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Union Find Tree (aka Disjoint Set Union)";
    commands["init"] = { "init {size}", action_init };
    commands["find"] = { "find {v}", action_find };
    commands["unite"] = { "unite {u} {v}", action_unite };
    commands["dump"] = { "dump", action_dump };
}