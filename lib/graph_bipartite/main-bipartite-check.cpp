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
    int from, to;
    cin >> from >> to;
    if (from < 0 || from >= solver.size() ||
        to < 0 || to >= solver.size()
    ) {
        cout << "false" << endl;
        return;
    }
    solver.add_edge(from, to);
    cout << "true" << endl;
}

void action_solve() {
    bool ans = solver.solve();
    cout << (ans ? "true" : "false") << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Bipartite Check";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {from} {to}", action_add_edge };
    commands["solve"] = { "solve", action_solve };
}