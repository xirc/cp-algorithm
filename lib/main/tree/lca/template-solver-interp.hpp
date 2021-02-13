#pragma once

#include <bits/stdc++.h>
#include "template/template-main.hpp"


template <class Solver>
class SolverInterp {
    using SolverPtr = std::shared_ptr<Solver>;
    SolverPtr solver = SolverPtr(nullptr);
    std::vector<std::vector<size_t>> adj;

public:
    void action_init() {
        size_t size;
        std::cin >> size;
        adj.assign(size, std::vector<size_t>());
        solver = nullptr;
        std::cout << "true" << std::endl;
    }
    void action_add_edge() {
        size_t u, v;
        std::cin >> u >> v;
        if (u >= adj.size() ||
            v >= adj.size())
        {
            std::cout << "false" << std::endl;
            return;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
        solver = nullptr;
        std::cout << "true" << std::endl;
    }
    void action_query() {
        size_t u, v;
        std::cin >> u >> v;
        if (u >= adj.size() ||
            v >= adj.size())
        {
            std::cout << "false" << std::endl;
            return;
        }
        if (solver == nullptr) {
            solver = SolverPtr(new Solver(adj));
        }
        size_t ans = solver->query(u, v);
        std::cout << ans << std::endl;
    }
};

template<class Interp>
void setup(Interp* interp, std::string& header, std::map<std::string,Command>& commands) {
    commands["init"] = { "init {size}", std::bind(&Interp::action_init, interp) };
    commands["edge"] = { "edge {u} {v}", std::bind(&Interp::action_add_edge, interp) };
    commands["query"] = { "query {u} {v}", std::bind(&Interp::action_query, interp) };
}