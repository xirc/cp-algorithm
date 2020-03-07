#pragma once

#include <functional>
#include "../template-main.hpp"

template <class Solver>
class SolverInterp {
    using SolverPtr = std::shared_ptr<Solver>;
    SolverPtr solver = SolverPtr(nullptr);
    std::vector<std::vector<int>> adj;

public:
    void action_init() {
        int size;
        std::cin >> size;
        if (size < 0) {
            std::cout << "false" << std::endl;
            return;
        }
        adj.assign(size, std::vector<int>());
        solver = nullptr;
        std::cout << "true" << std::endl;
    }
    void action_add_edge() {
        int u, v;
        std::cin >> u >> v;
        if (u < 0 || u >= adj.size() ||
            v < 0 || v >= adj.size())
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
        int u, v;
        std::cin >> u >> v;
        if (u < 0 || u >= adj.size() ||
            v < 0 || v >= adj.size())
        {
            std::cout << "false" << std::endl;
            return;
        }
        if (solver == nullptr) {
            solver = SolverPtr(new Solver(adj));
        }
        int ans = solver->query(u, v);
        std::cout << ans << std::endl;
    }
};

template<class Interp>
void setup(Interp* interp, std::string& header, std::map<std::string,Command>& commands) {
    commands["init"] =
        Command { "init {size}", bind(&Interp::action_init, interp) };
    commands["edge"] =
        Command { "edge {u} {v}", bind(&Interp::action_add_edge, interp) };
    commands["query"] =
        Command { "query {u} {v}", bind(&Interp::action_query, interp) };
}