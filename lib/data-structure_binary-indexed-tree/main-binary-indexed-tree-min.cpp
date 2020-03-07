#include <iostream>
#include <map>
#include <string>
#include <functional>
#include "binary-indexed-tree-min.hpp"
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

void action_min() {
    int index;
    cin >> index;
    auto ans = tree->min(index);
    cout << ans << endl;
}

void action_update() {
    int index, value;
    cin >> index >> value;
    if (index < 0 || index >= tree->size()) {
        cout << "false" << endl;
        return;
    }
    tree->update(index, value);
    cout << "true" << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binary Indexed Tree";
    commands["init"] =
        Command { "init {size}", action_init };
    commands["min"] =
        Command { "min {index}", action_min };
    commands["update"] =
        Command { "update {index} {value}", action_update };
}