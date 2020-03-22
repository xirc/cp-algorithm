#include <iostream>
#include <map>
#include <string>
#include <functional>
#include "binary-indexed-tree-rupq.hpp"
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

void action_query() {
    int index;
    cin >> index;
    auto ans = bit.get(index);
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
        cout << bit.get(i);
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binary Indexed Tree";
    commands["init"] = { "init {size}", action_init };
    commands["query"] = { "query {index}", action_query };
    commands["add"] = { "add {l} {r} {value}", action_add };
    commands["dump"] = { "dump", action_dump };
}