#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include "../template-main.hpp"

template <class Solver>
class Interp {
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
        std::cout << "true" << std::endl;
    }

    void action_add_edge() {
        int from, to; long long distance;
        std::cin >> from >> to >> distance;
        if (from < 0 ||
            from > solver->size() ||
            to < 0 ||
            to > solver->size() ||
            distance < 0
        ) {
            std::cout << "false" << std::endl;
            return;
        }
        solver->add_edge(from, to, distance);
        std::cout << "true" << std::endl;
    }

    void action_solve() {
        int s;
        std::cin >> s;
        if (s < 0 || s >= solver->size()) {
            std::cout << "false" << std::endl;
            return;
        }

        const int n = solver->size();
        std::vector<long long> distance;
        std::vector<int> parent;
        solver->solve(s, distance, parent);

        for (int i = 0; i < n; ++i) {
            if (i == s) continue;

            std::vector<int> path;
            for (int v = parent[i]; v != -1; v = parent[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            if (path.size() > 0) path.push_back(i);

            std::cout << "path: ";
            for (int j = 0; j < path.size(); ++j) {
                if (j > 0) std::cout << " -> ";
                std::cout << path[j];
            }
            std::cout << ", distance: " << distance[i] << std::endl;
        }
    }
};

template<class SolverInterp>
void setup(SolverInterp* interp, std::string& header, std::map<std::string,Command>& commands){
    header = "Dijkstra with Priority Queue";
    commands["init"] = { "init {size}", std::bind(&SolverInterp::action_init, interp) };
    commands["add"] = { "add {from} {to} {distance}", std::bind(&SolverInterp::action_add_edge, interp) };
    commands["solve"] = { "solve {source}", std::bind(&SolverInterp::action_solve, interp) };
}