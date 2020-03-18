#include <iostream>
#include "../template-main.hpp"
#include "./tree-diameter.hpp"

using namespace std;

TreeDiameter solver(0);

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = TreeDiameter(size);
    cout << "true" << endl;
}

void action_edge() {
    int u, v;
    long long w;
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
    int u, v;
    long long w;
    auto e = solver.solve();
    tie(u, v, w) = e;
    cout << u << " " << v << " " << w << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Diameter of a Tree";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {u} {v} {w}", action_edge };
    commands["solve"] = { "solve", action_solve };
}