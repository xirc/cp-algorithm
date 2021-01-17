#pragma once

#include <bits/stdc++.h>
#include "template/template-main.hpp"

template <class Solver>
class SolverInterp {
    Solver solver;

public:
    void action_init() {
        size_t n;
        std::cin >> n;
        solver = Solver(n);
    }
    void action_add_edge() {
        size_t from, to;
        long long cost;
        std::cin >> from >> to >> cost;
        if (from >= solver.size() ||
            to >= solver.size())
        {
            std::cout << "false" << std::endl;
            return;
        }
        solver.add_edge(from, to, cost);
    }
    void action_solve() {
        size_t from;
        std::vector<int64_t> distance;
        std::vector<size_t> predecessor;
        std::cin >> from;
        if (from >= solver.size())
        {
            std::cout << "false" << std::endl;
            return;
        }
        bool has_ans = solver.solve(from, distance, predecessor);
        if (!has_ans) {
            std::cout << "false" << std::endl;
            return;
        }
        for (size_t to = 0; to < solver.size(); ++to) {
            std::cout << "distance: " << distance[to] << ", ";
            std::cout << "path: ";
            std::vector<size_t> path;
            for (size_t v = predecessor[to]; v != solver.size(); v = predecessor[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            if (path.size() > 0) {
                path.push_back(to);
            }
            for (size_t i = 0; i < path.size(); ++i) {
                if (i > 0) std::cout << " ";
                std::cout << path[i];
            }
            std::cout << std::endl;
        }
    }
};

template <class SolverInterp>
void setup(SolverInterp *interp, std::string& header, std::map<std::string,Command> &commands) {
    commands["init"] = { "init {size}", std::bind(&SolverInterp::action_init, interp) };
    commands["add-edge"] = { "add-edge {from} {to} {cost}", std::bind(&SolverInterp::action_add_edge, interp) };
    commands["solve"] = { "solve {from}", std::bind(&SolverInterp::action_solve, interp) };
}