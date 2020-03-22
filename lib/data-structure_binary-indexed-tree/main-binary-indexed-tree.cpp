#include <iostream>
#include <map>
#include <string>
#include <functional>
#include "binary-indexed-tree.hpp"
#include "../template-main.hpp"

using namespace std;

using BIT = BinaryIndexedTree<long long>;
BIT bit;

void action_init() {
    int size;
    cin >> size;
    if (size <= 0) {
        cout << "false" << endl;
        return;
    }
    bit = BIT(size);
    cout << "true" << endl;
}

void action_sum() {
    int l, r;
    cin >> l >> r;
    if (l < 0 || l > bit.size() ||
        r < 0 || r > bit.size())
    {
        cout << "false" << endl;
        return;
    }
    auto ans = bit.sum(l, r);
    cout << ans << endl;
}

void action_add() {
    int index, value;
    cin >> index >> value;
    if (index < 0 || index >= bit.size()) {
        cout << "false" << endl;
        return;
    }
    bit.add(index, value);
    cout << "true" << endl;
}

void action_set() {
    int index, value;
    cin >> index >> value;
    if (index < 0 || index >= bit.size()) {
        cout << "false" << endl;
        return;
    }
    bit.set(index, value);
    cout << "true" << endl;
}

void action_dump() {
    for (int i = 0; i < bit.size(); ++i) {
        if (i > 0) cout << " ";
        cout << bit.sum(i, i+1);
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binary Indexed Tree";
    commands["init"] = { "init {size}", action_init };
    commands["sum"] = { "sum {l} {r}", action_sum };
    commands["add"] = { "add {index} {value}", action_add };
    commands["set"] = { "set {index} {value}", action_set };
    commands["dump"] = { "dump", action_dump };
}