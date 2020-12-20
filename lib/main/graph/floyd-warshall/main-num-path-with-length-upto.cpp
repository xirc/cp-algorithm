// Find the number of paths of length<='k' between vertices.

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <memory>
#include "template/template-main.hpp"
#include "num-path-of-fixed-length.hpp"

using namespace std;

Solver solver;

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = Solver(2 * size);
    const int N = size;
    for (int i = 0; i < N; ++i) {
        solver.add_edge(i, i + N);
        solver.add_edge(i + N, i + N);
    }
    cout << "true" << endl;
}

void action_add_edge() {
    const int N = solver.size() / 2;
    int from, to;
    cin >> from >> to;
    if (from < 0 || from >= N ||
        to < 0 || to >= N)
    {
        cout << "false" << endl;
        return;
    }
    solver.add_edge(from, to);
    cout << "true" << endl;
}

void action_solve() {
    int length;
    cin >> length;
    if (length <= 0) {
        cout << "false" << endl;
        return;
    }
    const int N = solver.size() / 2;
    auto G = solver.solve(length + 1);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j > 0) cout << " ";
            cout << G[i][j+N];
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