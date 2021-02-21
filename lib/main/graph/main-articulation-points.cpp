#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/graph/articulation_points.hpp"

using namespace std;

ArticulationPoints solver;

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = ArticulationPoints(size);
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
    auto cutpoints = solver.solve();
    for (int i = 0; i < cutpoints.size(); ++i) {
        if (i > 0) cout << " ";
        cout << cutpoints[i];
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Articulation Points of a Graph";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {u} {v}", action_edge };
    commands["solve"] = { "solve", action_solve };
}