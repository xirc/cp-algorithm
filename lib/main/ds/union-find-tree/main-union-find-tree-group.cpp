#include <bits/stdc++.h>
#include "cpalgo/ds/union-find-tree-group.hpp"
#include "template/template-main.hpp"

using namespace std;

UnionFindTree<int> tree;

string to_string(UnionFindTree<int>::node node) {
    return "(" + to_string(node.leader) + "," + to_string(node.weight) + ")";
}

void action_init() {
    size_t size;
    cin >> size;
    tree = UnionFindTree<int>(size);
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
    int w;
    cin >> u >> v >> w;
    if (u >= tree.size()) {
        cout << "false" << endl;
        return;
    }
    if (v >= tree.size()) {
        cout << "false" << endl;
        return;
    }
    auto ans = tree.unite(u, v, w);
    cout << (ans ? "true" : "false") << endl;
}

void action_diff() {
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
    int w;
    if (tree.diff(u, v, w)) {
        cout << w << endl;
    } else {
        cout << "false" << endl;
    }
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
    header = "Weighted Union Find Tree";
    commands["init"] = { "init {size}", action_init };
    commands["find"] = { "find {v}", action_find };
    commands["unite"] = { "unite {u} {v} {w}", action_unite };
    commands["diff"] = { "diff {u} {v}", action_diff };
    commands["dump"] = { "dump", action_dump };
}