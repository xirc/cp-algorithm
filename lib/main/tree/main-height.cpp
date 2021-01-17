#include <iostream>
#include <memory>
#include "template/template-main.hpp"
#include "cpalgo/tree/height.hpp"

using namespace std;

TreeHeight solver;

void action_init() {
    size_t size;
    cin >> size;
    solver = TreeHeight(size);
    cout << "true" << endl;
}

void action_edge() {
    size_t u, v;
    uint64_t w;
    cin >> u >> v >> w;
    if (u >= solver.size() ||
        v >= solver.size())
    {
        cout << "false" << endl;
        return;
    }
    solver.add_edge(u, v, w);
    cout << "true" << endl;
}

void action_solve() {
    auto height = solver.solve();
    for (size_t v = 0; v < height.size(); ++v) {
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