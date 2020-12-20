#include <iostream>
#include <numeric>
#include <algorithm>
#include "cpalgo/ds/binary-indexed-tree.hpp"
#include "template/template-main.hpp"

using namespace std;

using BIT = BinaryIndexedTree<long long>;
BIT make_bit(int N) {
    auto id = numeric_limits<long long>::max();
    auto plus = [&](const long long& lhs, const long long& rhs) {
        return min(lhs, rhs);
    };
    auto minus = [&](const long long& lhs, const long long& rhs) -> long long {
        throw;
    };
    return BIT(N, numeric_limits<long long>::max(), plus, minus);
};
BIT bit;

void action_init() {
    int size;
    cin >> size;
    if (size <= 0) {
        cout << "false" << endl;
        return;
    }
    bit = make_bit(size);
    cout << "true" << endl;
}

void action_min() {
    int index;
    cin >> index;
    auto ans = bit.sum(index);
    cout << ans << endl;
}

void action_update() {
    int index, value;
    cin >> index >> value;
    if (index < 0 || index >= bit.size()) {
        cout << "false" << endl;
        return;
    }
    bit.add(index, value);
    cout << "true" << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binary Indexed Tree";
    commands["init"] = { "init {size}", action_init };
    commands["min"] = { "min {index}", action_min };
    commands["update"] = { "update {index} {value}", action_update };
}