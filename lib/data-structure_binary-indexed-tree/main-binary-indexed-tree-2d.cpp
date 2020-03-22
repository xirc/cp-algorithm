#include <iostream>
#include <map>
#include <string>
#include <functional>
#include "binary-indexed-tree-2d.hpp"
#include "../template-main.hpp"

using namespace std;

using BIT = BinaryIndexedTree<long long>;
BIT bit;

void action_init() {
    int size_n, size_m;
    cin >> size_n >> size_m;
    if (size_n <= 0 || size_m <= 0) {
        cout << "false" << endl;
        return;
    }
    bit = BIT(size_n, size_m);
    cout << "true" << endl;
}

void action_sum() {
    int N, M;
    tie(N, M) = bit.size();
    int x, y;
    cin >> x >> y;
    if (x < 0 || x > N || y < 0 || y > M) {
        cout << "false" << endl;
        return;
    }
    auto ans = bit.sum(x, y);
    cout << ans << endl;
}

void action_add() {
    int N, M;
    tie(N, M) = bit.size();
    int x, y, value;
    cin >> x >> y >> value;
    if (x < 0 || x >= N || y < 0 || y >= M) {
        cout << "false" << endl;
        return;
    }
    bit.add(x, y, value);
    cout << "true" << endl;
}

void action_set() {
    int N, M;
    tie(N, M) = bit.size();
    int x, y, value;
    cin >> x >> y >> value;
    if (x < 0 || x >= N || y < 0 || y >= M) {
        cout << "false" << endl;
        return;
    }
    bit.set(x, y, value);
    cout << "true" << endl;
}

void action_dump() {
    int N, M;
    tie(N,M) = bit.size();
    for (int y = 0; y < M; ++y) {
        if (y > 0) cout << endl;
        for (int x = 0; x < N; ++x) {
            if (x > 0) cout << " ";
            cout << bit.sum(x, x+1, y, y+1);
        }
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binary Indexed Tree";
    commands["init"] = { "init {size_n} {size_m}", action_init };
    commands["sum"] = { "sum {x} {y}", action_sum };
    commands["add"] = { "add {x} {y} {value}", action_add };
    commands["set"] = { "set {x} {y} {value}", action_add };
    commands["dump"] = { "dump", action_dump };
}