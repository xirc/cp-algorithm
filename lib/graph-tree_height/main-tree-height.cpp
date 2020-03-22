#include <iostream>
#include "../template-main.hpp"
#include "./tree-height.hpp"

using namespace std;

TreeHeight solver;

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = TreeHeight(size);
    cout << "true" << endl;
}

void action_edge() {
    int u, v, w;
    cin >> u >> v >> w;
    if (u < 0 || u >= solver.size() ||
        v < 0 || v >= solver.size())
    {
        cout << "false" << endl;
        return;
    }
    solver.add_edge(u, v, w);
    cout << "true" << endl;
}

void action_solve() {
    auto height = solver.solve();
    for (int v = 0; v < height.size(); ++v) {
        if (v > 0) cout << " ";
        cout << height[v];
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Height of a Tree";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {u} {v} {w}", action_edge };
    commands["solve"] = { "solve", action_solve };
}