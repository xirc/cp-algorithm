#include <iostream>
#include <map>
#include <string>
#include <functional>
#include "binary-indexed-tree-2d.hpp"
#include "../template-main.hpp"

using namespace std;
using Tree = shared_ptr<BinaryIndexedTree>;

Tree tree = Tree(new BinaryIndexedTree(0,0));

void action_init() {
    int size_n, size_m;
    cin >> size_n >> size_m;
    if (size_n <= 0 || size_m <= 0) {
        cout << "false" << endl;
        return;
    }
    tree = Tree(new BinaryIndexedTree(size_n, size_m));
    cout << "true" << endl;
}

void action_sum() {
    int x, y;
    cin >> x >> y;
    auto ans = tree->sum(x, y);
    cout << ans << endl;
}

void action_add() {
    int x, y, value;
    cin >> x >> y >> value;
    if (x < 0 || x >= tree->size().first || y < 0 || y >= tree->size().second) {
        cout << "false" << endl;
        return;
    }
    tree->add(x, y, value);
    cout << "true" << endl;
}

void action_dump() {
    for (int y = 0; y < tree->size().second; ++y) {
        if (y > 0) cout << endl;
        for (int x = 0; x < tree->size().first; ++x) {
            if (x > 0) cout << " ";
            cout << tree->sum(x, x+1, y, y+1);
        }
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binary Indexed Tree";
    commands["init"] =
        Command { "init {size_n} {size_m}", action_init };
    commands["sum"] =
        Command { "sum {x} {y}", action_sum };
    commands["add"] =
        Command { "add {x} {y} {value}", action_add };
    commands["dump"] =
        Command { "dump", action_dump };
}