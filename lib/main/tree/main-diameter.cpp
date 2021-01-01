#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/tree/diameter.hpp"

using namespace std;

TreeDiameter solver;

void action_init() {
    size_t size;
    cin >> size;
    solver = TreeDiameter(size);
    cout << "true" << endl;
}

void action_edge() {
    size_t u, v;
    unsigned long long w;
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
    size_t u, v;
    unsigned long long w;
    tie(u, v, w) = solver.solve();
    cout << u << " " << v << " " << w << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Diameter of a Tree";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {u} {v} {w}", action_edge };
    commands["solve"] = { "solve", action_solve };
}