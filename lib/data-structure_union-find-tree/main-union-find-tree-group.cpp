#include <map>
#include <string>
#include "union-find-tree-group.hpp"
#include "../template-main.hpp"

using namespace std;

UnionFindTree<int> tree;

string to_string(UnionFindTree<int>::node node) {
    return "(" + to_string(node.leader) + "," + to_string(node.weight) + ")";
}

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    tree = UnionFindTree<int>(size);
    cout << "true" << endl;
}

void action_find() {
    int v;
    cin >> v;
    if (v < 0 || v >= tree.size()) {
        cout << -1 << endl;
        return;
    }
    auto ans = tree.find(v);
    cout << to_string(ans) << endl;
}

void action_union() {
    int u, v, w;
    cin >> u >> v >> w;
    if (u < 0 || u >= tree.size()) {
        cout << "false" << endl;
        return;
    }
    if (v < 0 || v >= tree.size()) {
        cout << "false" << endl;
        return;
    }
    auto ans = tree.unite(u, v, w);
    cout << (ans ? "true" : "false") << endl;
}

void action_diff() {
    int u, v;
    cin >> u >> v;
    if (u < 0 || u >= tree.size()) {
        cout << "false" << endl;
        return;
    }
    if (v < 0 || v >= tree.size()) {
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
    for (int i = 0; i < tree.size(); ++i) {
        if (i != 0) cout << " ";
        auto value = tree.find(i);
        cout << to_string(value);
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Weighted Union Find Tree";
    commands["init"] = { "init {size}", action_init };
    commands["find"] = { "find {v}", action_find };
    commands["union"] = { "union {u} {v} {w}", action_union };
    commands["diff"] = { "diff {u} {v}", action_diff };
    commands["dump"] = { "dump", action_dump };
}