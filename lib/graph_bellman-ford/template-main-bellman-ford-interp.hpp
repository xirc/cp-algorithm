#pragma once

#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <memory>
#include "../template-main.hpp"

template <class Solver>
class SolverInterp {
    using SolverPtr = std::shared_ptr<Solver>;
    SolverPtr solver = SolverPtr(new Solver());

public:
    void action_init() {
        int n;
        std::cin >> n;
        if (n < 0) {
            std::cout << "false" << std::endl;
            return;
        }
        solver = SolverPtr(new Solver(n));
    }
    void action_add_edge() {
        int from, to; long long cost;
        std::cin >> from >> to >> cost;
        if (from < 0 || from >= solver->size() ||
            to < 0 || to >= solver->size())
        {
            std::cout << "false" << std::endl;
            return;
        }
        solver->add_edge(from, to, cost);
    }
    void action_solve() {
        int from;
        std::vector<long long> distance;
        std::vector<int> predecessor;
        std::cin >> from;
        if (from < 0 || from >= solver->size())
        {
            std::cout << "false" << std::endl;
            return;
        }
        bool has_ans = solver->solve(from, distance, predecessor);
        if (!has_ans) {
            std::cout << "false" << std::endl;
            return;
        }
        for (int to = 0; to < solver->size(); ++to) {
            std::cout << "distance: " << distance[to] << ", ";
            std::cout << "path: ";
            std::vector<int> path;
            for (int v = predecessor[to]; v != -1; v = predecessor[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            if (path.size() > 0) {
                path.push_back(to);
            }
            for (int i = 0; i < path.size(); ++i) {
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