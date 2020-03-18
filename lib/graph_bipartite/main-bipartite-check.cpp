#include <iostream>
#include "../template-main.hpp"
#include "./bipartite-check.hpp"

using namespace std;

BipartiteCheck solver(0);

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = BipartiteCheck(size);
    cout << "true" << endl;
}

void action_add_edge() {
    int u, v;
    cin >> u >> v;
    if (u < 0 || u >= solver.size() ||
        v < 0 || v >= solver.size()
    ) {
        cout << "false" << endl;
        return;
    }
    solver.add_edge(u, v);
    cout << "true" << endl;
}

void action_solve() {
    bool ans = solver.solve();
    cout << (ans ? "true" : "false") << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Bipartite Check";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {u} {v}", action_add_edge };
    commands["solve"] = { "solve", action_solve };
}