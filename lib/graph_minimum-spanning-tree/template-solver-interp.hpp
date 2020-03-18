#include <iostream>
#include <functional>
#include "../template-main.hpp"

template <class Solver>
class SolverInterp {
    using SolverPtr = std::shared_ptr<Solver>;
    SolverPtr solver = SolverPtr(new Solver(0));
public:
    void action_init() {
        int size;
        std::cin >> size;
        if (size < 0) {
            std::cout << "false" << std::endl;
            return;
        }
        solver = SolverPtr(new Solver(size));
    }
    void action_add_edge() {
        int u, v;
        long long distance;
        std::cin >> u >> v >> distance;
        if (u < 0 || u >= solver->size() ||
            v < 0 || v >= solver->size())
        {
            std::cout << "false" << std::endl;
            return;
        }
        solver->add_edge(u, v, distance);
    }
    void action_solve() {
        long long distance;
        std::vector<std::pair<int,int>> edges;
        bool has_ans = solver->solve(distance, edges);
        if (!has_ans) {
            std::cout << "false" << std::endl;
            return;
        }
        std::cout << distance << std::endl;
        for (int i = 0; i < edges.size(); ++i) {
            std::cout << edges[i].first << " - " << edges[i].second << std::endl;
        }
    }
};

template <class Interp>
void setup(Interp *interp, std::string& header, std::map<std::string,Command>& commands) 
{
    commands["init"] = { "init {size}", bind(&Interp::action_init, interp) };
    commands["edge"] = { "edge {u} {v} {distance}", bind(&Interp::action_add_edge, interp) };
    commands["solve"] = { "solve", bind(&Interp::action_solve, interp) };
}