#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <random>
#include <climits>
#include <algorithm>
#include "../template-main.hpp"
#include "sqrt-decomposition.hpp"

using namespace std;

struct Max {
    static long long id() { return LONG_LONG_MIN; }
    static long long op(const long long& lhs, const long long& rhs) {
        return std::max(lhs, rhs);
    }
};
SqrtDecomposition<int,Max> container;

void action_init() {
    int n, _min, _max;
    random_device random;
    cin >> n >> _min >> _max;
    if (n < 0) {
        cout << "false" << endl;
        return;
    }
    vector<int> array(n, 0);
    for (int i = 0 ; i < n; ++i) {
        array[i] = random() % (_max - _min) + _min;
    }
    container.build(array);
    cout << "true" << endl;
}

void action_query() {
    int l, r;
    cin >> l >> r;
    int ans = container.query(l, r);
    cout << ans << endl;
}

void action_update() {
    int i, v;
    cin >> i >> v;
    if (i < 0 || i > container.size()) {
        cout << "false" << endl;
        return;
    }
    container.update(i, v);
    cout << "true" << endl;
}

void action_dump() {
    vector<int> buffer;
    container.dump(buffer);
    for (int i = 0; i < buffer.size(); ++i) {
        if (i > 0) cout << " ";
        cout << buffer[i];
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Sum Query using Sqrt Decomposition";
    commands["init"] =
        Command { "init {size} {min} {max}", action_init };
    commands["max"] =
        Command { "max {l} {r}", action_query };
    commands["update"] =
        Command { "update {index} {value}", action_update };
    commands["dump"] =
        Command { "dump", action_dump };
}