#include <iostream>
#include <memory>
#include "template/template-main.hpp"
#include "cpalgo/graph/finding-cycle.hpp"

using namespace std;

using SolverPtr = shared_ptr<Solver>;
SolverPtr solver = SolverPtr(new Solver());

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = SolverPtr(new Solver(size));
    cout << "true" << endl;
}

void action_add_edge() {
    int from, to;
    cin >> from >> to;
    if (from < 0 || from >= solver->size() ||
        to < 0 || to >= solver->size())
    {
        cout << "false" << endl;
        return;
    }
    solver->add_edge(from, to);
    cout << "true" << endl;
}

void action_solve() {
    vector<int> cycle;
    bool has_cycle = solver->solve(cycle);
    if (!has_cycle) {
        cout << "false" << endl;
        return;
    }
    for (int i = 0; i < cycle.size(); ++i) {
        if (i > 0) cout << " ";
        cout << cycle[i];
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Finding a cycle of a graph";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {from} {to}", action_add_edge };
    commands["solve"] = { "solve", action_solve };
}