#pragma once

#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include "../template-main.hpp"

template <class Solver>
class SolverInterp {
    using SolverPtr = std::shared_ptr<Solver>;
    SolverPtr solver = SolverPtr(new Solver());

public:
    void action_init() {
        int n;
        cin >> n;
        if (n < 0) {
            cout << "false" << endl;
            return;
        }
        solver = SolverPtr(new Solver(n));
    }
    void action_add_edge() {
        int from, to; long long cost;
        cin >> from >> to >> cost;
        if (from < 0 || from >= solver->size() ||
            to < 0 || to >= solver->size())
        {
            cout << "false" << endl;
            return;
        }
        solver->add_edge(from, to, cost);
    }
    void action_solve() {
        int from;
        std::vector<long long> distance;
        std::vector<int> predecessor;
        cin >> from;
        if (from < 0 || from >= solver->size())
        {
            cout << "false" << endl;
            return;
        }
        bool has_ans = solver->solve(from, distance, predecessor);
        if (!has_ans) {
            cout << "false" << endl;
            return;
        }
        for (int to = 0; to < solver->size(); ++to) {
            cout << "distance: " << distance[to] << ", ";
            cout << "path: ";
            std::vector<int> path;
            for (int v = predecessor[to]; v != -1; v = predecessor[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            if (path.size() > 0) {
                path.push_back(to);
            }
            for (int i = 0; i < path.size(); ++i) {
                if (i > 0) cout << " ";
                cout << path[i];
            }
            cout << endl;
        }
    }
};

template <class SolverInterp>
void setup(SolverInterp *interp, std::string& header, std::map<std::string,Command> &commands) {
    commands["init"] = { "init {size}", bind(&SolverInterp::action_init, interp) };
    commands["add-edge"] = { "add-edge {from} {to} {cost}", bind(&SolverInterp::action_add_edge, interp) };
    commands["solve"] = { "solve {from}", bind(&SolverInterp::action_solve, interp) };
}