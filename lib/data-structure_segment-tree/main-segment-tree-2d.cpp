#include <iostream>
#include <map>
#include <string>
#include <random>
#include <cmath>
#include "segment-tree-2d.hpp"
#include "../template-main.hpp"

using namespace std;
using row = vector<int>;
using matrix = vector<row>;

SegmentTree tree(4,4);
matrix buffer;

void action_random() {
    int n, m, minv, maxv;
    random_device random;
    cin >> n >> m >> minv >> maxv;

    auto mat = matrix(n, row(m));
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            mat[x][y] = (random() % abs(maxv - minv)) + minv;
        }
    }
    tree.build(mat);
}

void action_dump() {
    tree.dump(buffer);
    for (int y = 0; y < tree.size_y(); ++y) {
        if (y > 0) cout << endl;
        for (int x = 0; x < tree.size_x(); ++x) {
            if (x > 0) cout << " ";
            cout << buffer[x][y];
        }
    }
    cout << endl;
}

void action_query() {
    int lx, rx, ly, ry;
    cin >> lx >> rx >> ly >> ry;
    int ans = tree.sum(lx, rx, ly, ry);
    cout << ans << endl;
}

void action_update() {
    int x, y, value;
    cin >> x >> y >> value;
    bool ans = tree.update(x, y, value);
    cout << (ans ? "true" : "false") << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Segment Tree 2D";
    commands["random"] = { "random {n} {m} {min} {max}", action_random };
    commands["dump"] = { "dump", action_dump };
    commands["query"] = { "query {lx} {rx} {ly} {ry}", action_query };
    commands["update"] = { "update {x} {y} {value}", action_update };
}