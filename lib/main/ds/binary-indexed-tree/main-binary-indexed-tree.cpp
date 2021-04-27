#include <iostream>
#include <map>
#include <string>
#include <functional>
#include "cpalgo/ds/binary_indexed_tree.hpp"
#include "template/template-main.hpp"

using namespace std;

using BIT = BinaryIndexedTree<int>;
BIT bit;

void action_init() {
    size_t size;
    cin >> size;
    bit = BIT(size);
    cout << "true" << endl;
}

void action_sum() {
    size_t l, r;
    cin >> l >> r;
    if (l >= bit.size() ||
        r > bit.size())
    {
        cout << "false" << endl;
        return;
    }
    auto ans = bit.fold(l, r);
    cout << ans << endl;
}

void action_add() {
    size_t index;
    int value;
    cin >> index >> value;
    if (index >= bit.size()) {
        cout << "false" << endl;
        return;
    }
    bit.combine(index, value);
    cout << "true" << endl;
}

void action_dump() {
    for (size_t i = 0; i < bit.size(); ++i) {
        if (i > 0) cout << " ";
        cout << bit.fold(i, i+1);
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binary Indexed Tree";
    commands["init"] = { "init {size}", action_init };
    commands["sum"] = { "sum {l} {r}", action_sum };
    commands["add"] = { "add {index} {value}", action_add };
    commands["dump"] = { "dump", action_dump };
}