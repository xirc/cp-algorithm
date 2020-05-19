#include <iostream>
#include <algorithm>
#include <numeric>
#include "kdtree.hpp"
#include "../template-main.hpp"

using namespace std;

KDTree<double,2> tree;
vector<array<double,2>> points;

void action_init() {
    tree.clear();
    points.clear();
}

void action_insert() {
    double x, y, z;
    cin >> x >> y;
    int i = points.size();
    tree.insert(i, { x, y });
    points.push_back({ x, y });
}

void action_search() {
    double lx, ly;
    double ux, uy;
    cin >> lx >> ly;
    cin >> ux >> uy;

    vector<int> ans;
    tree.search({lx, ly}, {ux, uy}, ans);

    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << points[i][0] << " " << points[i][1] << endl;
    }
}

void setup(string& header, map<string,Command>& commands) {
    header = "kD Tree";
    commands["init"] = { "init", action_init };
    commands["insert"] = { "insert x y", action_insert };
    commands["search"] = { "search lx ly ux uy", action_search };
}