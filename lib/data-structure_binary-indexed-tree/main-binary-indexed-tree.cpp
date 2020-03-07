#include <iostream>
#include <map>
#include <string>
#include <functional>
#include "binary-indexed-tree.hpp"
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

void action_sum() {
    int l, r;
    cin >> l >> r;
    auto ans = tree->sum(l, r);
    cout << ans << endl;
}

void action_add() {
    int index, value;
    cin >> index >> value;
    if (index < 0 || index >= tree->size()) {
        cout << "false" << endl;
        return;
    }
    tree->add(index, value);
    cout << "true" << endl;
}

void action_dump() {
    for (int i = 0; i < tree->size(); ++i) {
        if (i > 0) cout << " ";
        cout << tree->sum(i, i+1);
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binary Indexed Tree";
    commands["init"] =
        Command { "init {size}", action_init };
    commands["sum"] =
        Command { "sum {l} {r}", action_sum };
    commands["add"] =
        Command { "add {index} {value}", action_add };
    commands["dump"] =
        Command { "dump", action_dump };
}