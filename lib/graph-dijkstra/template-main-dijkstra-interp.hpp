#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../template-main.hpp"

template <class Solver>
class Interp {
    using SolverPtr = std::shared_ptr<Solver>;
    SolverPtr solver = SolverPtr(new Solver(0));
public:
    void action_init() {
        int n;
        cin >> n;
        if (n < 0) {
            cout << "false" << endl;
            return;
        }
        solver = SolverPtr(new Solver(n));
        cout << "true" << endl;
    }

    void action_add_edge() {
        int from, to, distance;
        cin >> from >> to >> distance;
        if (from < 0 ||
            from > solver->size() ||
            to < 0 ||
            to > solver->size() ||
            distance < 0
        ) {
            cout << "false" << endl;
            return;
        }
        solver->add_dir_edge(from, to, distance);
        cout << "true" << endl;
    }

    void action_solve() {
        int s;
        cin >> s;
        if (s < 0 || s >= solver->size()) {
            cout << "false" << endl;
            return;
        }

        const int n = solver->size();
        vector<int> distance, parent;
        solver->solve(s, distance, parent);

        for (int i = 0; i < n; ++i) {
            if (i == s) continue;

            vector<int> path;
            for (int v = parent[i]; v != -1; v = parent[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            if (path.size() > 0) path.push_back(i);

            cout << "path: ";
            for (int j = 0; j < path.size(); ++j) {
                if (j > 0) cout << " -> ";
                cout << path[j];
            }
            cout << ", distance: " << distance[i] << endl;
        }
    }
};

template<class SolverInterp>
void setup(SolverInterp* interp, std::string& header, std::map<std::string,Command>& commands){
    header = "Dijkstra with Priority Queue";
    commands["init"] =
        Command { "init {size}", bind(&SolverInterp::action_init, interp) };
    commands["add"] =
        Command { "add {from} {to} {distance}", bind(&SolverInterp::action_add_edge, interp) };
    commands["solve"] =
        Command { "solve {source}", bind(&SolverInterp::action_solve, interp) };
}