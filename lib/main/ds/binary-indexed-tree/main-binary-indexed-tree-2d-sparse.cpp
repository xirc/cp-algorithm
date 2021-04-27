#include <iostream>
#include <map>
#include <string>
#include <functional>
#include "cpalgo/ds/binary-indexed-tree-2d-sparse.hpp"
#include "template/template-main.hpp"

using namespace std;

using BIT = BinaryIndexedTree2D<int>;
BIT bit;

void action_init() {
    size_t size_n, size_m;
    cin >> size_n >> size_m;
    bit = BIT(size_n, size_m);
    cout << "true" << endl;
}

void action_sum() {
    size_t N, M;
    tie(N, M) = bit.size();
    size_t x, y;
    cin >> x >> y;
    if (x > N || y > M) {
        cout << "false" << endl;
        return;
    }
    auto ans = bit.fold(x, y);
    cout << ans << endl;
}

void action_add() {
    size_t N, M;
    tie(N, M) = bit.size();
    size_t x, y;
    int value;
    cin >> x >> y >> value;
    if (x >= N || y >= M) {
        cout << "false" << endl;
        return;
    }
    bit.combine(x, y, value);
    cout << "true" << endl;
}

void action_dump() {
    size_t N, M;
    tie(N,M) = bit.size();
    for (size_t y = 0; y < M; ++y) {
        if (y > 0) cout << endl;
        for (size_t x = 0; x < N; ++x) {
            if (x > 0) cout << " ";
            cout << bit.fold(x, x+1, y, y+1);
        }
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binary Indexed Tree";
    commands["init"] = { "init {size_n} {size_m}", action_init };
    commands["sum"] = { "sum {x} {y}", action_sum };
    commands["add"] = { "add {x} {y} {value}", action_add };
    commands["dump"] = { "dump", action_dump };
}