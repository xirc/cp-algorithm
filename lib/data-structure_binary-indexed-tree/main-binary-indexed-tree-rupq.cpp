#include <iostream>
#include <map>
#include <string>
#include <functional>
#include "binary-indexed-tree-rupq.hpp"
#include "../template-main.hpp"

using namespace std;
using Tree = shared_ptr<BinaryIndexedTree>;

Tree tree = Tree(new BinaryIndexedTree(0));

void action_init() {
    int size;
    cin >> size;
    if (size <= 0) {
        cout << "false" << endl;
        return;
    }
    tree = Tree(new BinaryIndexedTree(size));
    cout << "true" << endl;
}

void action_query() {
    int index;
    cin >> index;
    auto ans = tree->query(index);
    cout << ans << endl;
}

void action_add() {
    int l, r, value;
    cin >> l >> r >> value;
    tree->add(l, r, value);
    cout << "true" << endl;
}

void action_dump() {
    for (int i = 0; i < tree->size(); ++i) {
        if (i > 0) cout << " ";
        cout << tree->query(i);
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binary Indexed Tree";
    commands["init"] =
        Command { "init {size}", action_init };
    commands["query"] =
        Command { "query {index}", action_query };
    commands["add"] =
        Command { "add {l} {r} {value}", action_add };
    commands["dump"] =
        Command { "dump", action_dump };
}