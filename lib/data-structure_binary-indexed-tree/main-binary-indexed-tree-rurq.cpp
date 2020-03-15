#include <iostream>
#include <map>
#include <string>
#include <functional>
#include "binary-indexed-tree-rurq.hpp"
#include "../template-main.hpp"

using namespace std;

using BIT = BinaryIndexedTree<long long>;
BIT bit = BIT(0);

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
    auto ans = bit.sum(l, r);
    cout << ans << endl;
}

void action_add() {
    int l, r, value;
    cin >> l >> r >> value;
    bit.add(l, r, value);
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
    commands["add"] = { "add {l} {r} {value}", action_add };
    commands["dump"] = { "dump", action_dump };
}