#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <memory>
#include "template/template-main.hpp"
#include "cpalgo/graph/floyd-warshall.hpp"

using namespace std;

FloydWarshall solver;

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = FloydWarshall(size);
    cout << "true" << endl;
}

void action_define_edge() {
    int from, to; long long distance;
    cin >> from >> to >> distance;
    if (from < 0 || from >= solver.size() ||
        to < 0 || to >= solver.size())
    {
        cout << "false" << endl;
        return;
    }
    solver.define_edge(from, to, distance);
}

void action_solve() {
    const int N = solver.size();
    vector<vector<long long>> D;
    vector<vector<int>> P;
    auto has_ans = solver.solve(D, P);
    if (!has_ans) {
        cout << "false" << endl;
        return;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            auto path = solver.retrieve_path(D, P, i, j);
            cout << i << " to " << j << ":";
            cout << " distance=" << D[i][j];
            cout << ", path=";
            for (int k = 0; k < path.size(); ++k) {
                if (k > 0) cout << ",";
                cout << path[k];
            }
            cout << endl;
        }
    }
}

void setup(string& header, map<string,Command>& commands) {
    header = "Floyd Warshall";
    commands["init"] =
        Command { "init {size}", action_init };
    commands["edge"] =
        Command { "edge {from} {to} {distance}", action_define_edge };
    commands["solve"] =
        Command { "solve", action_solve };
}