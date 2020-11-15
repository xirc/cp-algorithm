#include <map>
#include <string>
#include "union-find-tree-generic.hpp"
#include "../template-main.hpp"

using namespace std;

struct Value {
    bool parity, bipartite;
    Value(int i): parity(false), bipartite(true) {}
    static void compress(Value& node, const Value& root) {
        node.parity ^= root.parity;
        node.bipartite = root.bipartite;
    }
    static void unite_same(Value& root, const Value& u, const Value& v) {
        if (u.parity == v.parity) {
            root.bipartite = false;
        }
    }
    static void unite_diff(Value& parent, Value& child, const Value& u, const Value& v) {
        child.parity = u.parity ^ v.parity ^ true;
        parent.bipartite &= child.bipartite;
    }
};

UnionFindTree<Value> tree;

string to_string(UnionFindTree<Value>::node node) {
    return "(" + to_string(node.leader) + "," + to_string(node.value.bipartite) + ")";
}

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    tree = UnionFindTree<Value>(size);
    cout << "true" << endl;
}

void action_find() {
    int index;
    cin >> index;
    if (index < 0 || index >= tree.size()) {
        cout << -1 << endl;
        return;
    }
    auto ans = tree.find(index);
    cout << to_string(ans) << endl;
}

void action_union() {
    int index1, index2;
    cin >> index1 >> index2;
    if (index1 < 0 || index1 >= tree.size()) {
        cout << "false" << endl;
        return;
    }
    if (index2 < 0 || index2 >= tree.size()) {
        cout << "false" << endl;
        return;
    }
    tree.unite(index1, index2);
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
    header = "Bipartite Check using Union Find Tree";
    commands["init"] = Command { "init {size}", action_init };
    commands["find"] = Command { "find {index}", action_find };
    commands["union"] = Command { "union {index1} {index2}", action_union };
    commands["dump"] = Command { "dump", action_dump };
}