// Find the number of paths of length='k' between vertices.

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <memory>
#include "../template-main.hpp"
#include "./num-path-of-fixed-length.hpp"

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
    int length;
    cin >> length;
    if (length <= 0) {
        cout << "false" << endl;
        return;
    }
    const int N = solver->size();
    auto G = solver->solve(length);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j > 0) cout << " ";
            cout << G[i][j];
        }
        cout << endl;
    }
}

void setup(string& header, map<string,Command>& commands) {
    header = "Number of paths of a fixed length";
    commands["init"] =
        Command { "init {size}", action_init };
    commands["add-edge"] =
        Command { "add-edge {from} {to}", action_add_edge };
    commands["solve"] =
        Command { "solve {length}", action_solve };
}