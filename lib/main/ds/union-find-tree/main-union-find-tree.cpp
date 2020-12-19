#include <map>
#include <string>
#include "cpalgo/ds/union-find-tree.hpp"
#include "template/template-main.hpp"

using namespace std;

UnionFindTree tree;

string to_string(UnionFindTree::node value) {
    return to_string(value.leader);
}

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    tree = UnionFindTree(size);
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
    tree.unite(u, v);
    cout << "true" << endl;
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
    header = "Union Find Tree";
    commands["init"] = { "init {size}", action_init };
    commands["find"] = { "find {v}", action_find };
    commands["union"] = { "union {u} {v}", action_union };
    commands["dump"] = { "dump", action_dump };
}