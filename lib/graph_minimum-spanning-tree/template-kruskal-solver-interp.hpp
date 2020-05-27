#include <iostream>
#include <functional>
#include "../template-main.hpp"

template <class Solver>
class SolverInterp {
    std::vector<std::tuple<int,int,long long>> edges;
    Solver solver;
public:
    void action_init() {
        int size;
        std::cin >> size;
        if (size < 0) {
            std::cout << "false" << std::endl;
            return;
        }
        edges.clear();
        solver = Solver(size);
    }
    void action_add_edge() {
        int u, v;
        long long distance;
        std::cin >> u >> v >> distance;
        if (u < 0 || u >= solver.size() ||
            v < 0 || v >= solver.size())
        {
            std::cout << "false" << std::endl;
            return;
        }
        int index = edges.size();
        edges.push_back(std::make_tuple(u, v, distance));
        solver.add_edge(index, u, v, distance);
    }
    void action_solve() {
        long long distance;
        std::vector<int> out_edges;
        bool has_ans = solver.solve(distance, out_edges);
        if (!has_ans) {
            std::cout << "false" << std::endl;
            return;
        }
        std::cout << distance << std::endl;
        for (int i : out_edges) {
            int from, to; long long distance;
            std::tie(from, to, distance) = edges[i];
            std::cout << i << ": " << from << " -> " << to << " cost=" << distance << std::endl;
        }
    }
};

template <class Interp>
void setup(Interp *interp, std::string& header, std::map<std::string,Command>& commands) 
{
    commands["init"] = { "init {size}", std::bind(&Interp::action_init, interp) };
    commands["edge"] = { "edge {u} {v} {distance}", std::bind(&Interp::action_add_edge, interp) };
    commands["solve"] = { "solve", std::bind(&Interp::action_solve, interp) };
}