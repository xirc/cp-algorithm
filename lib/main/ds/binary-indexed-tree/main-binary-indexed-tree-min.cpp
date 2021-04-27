#include <iostream>
#include <numeric>
#include <algorithm>
#include "cpalgo/ds/binary_indexed_tree.hpp"
#include "template/template-main.hpp"

using namespace std;

using BIT = BinaryIndexedTree<int>;
BIT make_bit(int N) {
    auto empty = numeric_limits<int>::max();
    auto combine = [&](int const& lhs, int const& rhs) {
        return min(lhs, rhs);
    };
    auto remove = [&](int const& lhs, int const& rhs) -> int {
        throw;
    };
    return BIT(N, empty, combine, remove);
};
BIT bit;

void action_init() {
    size_t size;
    cin >> size;
    bit = make_bit(size);
    cout << "true" << endl;
}

void action_min() {
    size_t index;
    cin >> index;
    auto ans = bit.fold(index);
    cout << ans << endl;
}

void action_update() {
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

void setup(string& header, map<string,Command>& commands) {
    header = "Binary Indexed Tree";
    commands["init"] = { "init {size}", action_init };
    commands["min"] = { "min {index}", action_min };
    commands["update"] = { "update {index} {value}", action_update };
}