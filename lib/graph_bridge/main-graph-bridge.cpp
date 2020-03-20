#include <iostream>
#include "../template-main.hpp"
#include "./graph-bridge.hpp"

using namespace std;

Bridge solver(0);

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = Bridge(size);
    cout << "true" << endl;
}

void action_edge() {
    int u, v;
    cin >> u >> v;
    if (u < 0 || u >= solver.size() ||
        v < 0 || v >= solver.size())
    {
        cout << "false" << endl;
        return;
    }
    solver.add_edge(u, v);
    cout << "true" << endl;
}

void action_solve() {
    auto bridges = solver.solve();
    for (int i = 0; i < bridges.size(); ++i) {
        int u, v;
        tie(u, v) = bridges[i];
        if (i > 0) cout << " ";
        cout << "(" << u << "," << v << ")";
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Bridge of a Graph";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {u} {v}", action_edge };
    commands["solve"] = { "solve", action_solve };
}