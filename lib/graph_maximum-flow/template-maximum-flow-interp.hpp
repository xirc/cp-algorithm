#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <set>
#include "../template-main.hpp"
#include "./minimum-cut.hpp"

template <class MaximumFlow>
class SolverInterp {
    using mat = std::vector<std::vector<long long>>;
    struct edge { int from, to; long long capacity; };
    int N;
    std::vector<edge> edges;
    MaximumFlow maxflow;
    MinimumCut mincut;

public:
    SolverInterp(): N(0), edges(), maxflow(), mincut() {}
    void action_init() {
        int size;
        std::cin >> size;
        if (size < 0) {
            std::cout << "false" << std::endl;
            return;
        }
        N = size;
        edges.clear();
        maxflow = MaximumFlow(N);
        mincut = MinimumCut(N);
        std::cout << "true" << std::endl;
    }
    void action_add_edge() {
        int from, to;
        long long capacity;
        std::cin >> from >> to >> capacity;
        if (from < 0 || from >= N ||
            to < 0 || to >= N)
        {
            std::cout << "false" << std::endl;
            return;
        }
        edges.push_back({ from, to, capacity });
        maxflow.add_edge(from, to, capacity);
        mincut.add_edge(from, to, capacity);
        std::cout << "true" << std::endl;
    }
    void action_clear_flow() {
        maxflow.clear_flow();
        cout << "true" << endl;
    }
    void action_solve() {
        int source, sink;
        std::cin >> source >> sink;
        if (source < 0 || source >= N ||
            sink < 0 || sink >= N)
        {
            std::cout << "false" << std::endl;
            return;
        }
        // Maximum Flow
        auto maximum_flow = maxflow.solve(source, sink);
        auto flow = maxflow.get_flow();
        dump_maximum_flow(maximum_flow, flow);
        // Minimum Cut
        std::set<int> setS, setT;
        mincut.solve(source, sink, flow, setS, setT);
        dump_minimum_cut(setS, setT);
    }

private:
    void dump_maximum_flow(long long maxflow, mat flow) {
        std::cout << "Maximum Flow" << std::endl;
        std::cout << maxflow << std::endl;
        for (auto e : edges) {
            auto cap = e.capacity;
            auto f = std::min(cap, flow[e.from][e.to]);
            flow[e.from][e.to] -= f;
            std::cout << e.from << "->" << e.to << ": " << f << "/" << cap << std::endl;
        }
        std::cout << std::endl;
    }
    void dump_minimum_cut(const std::set<int>& setS, const std::set<int>& setT) {
        std::cout << "Minimum Cut" << std::endl;
        dump_set("S:", setS);
        dump_set("T:", setT);
    }
    void dump_set(const std::string& prefix, const std::set<int>& set) {
        cout << prefix;
        for (auto u : set) {
            cout << " " << u;
        }
        cout << endl;
    }
};

template <class Interp>
void setup(Interp* interp, std::map<std::string,Command>& commands) {
    commands["init"] = { "init {size}", std::bind(&Interp::action_init, interp) };
    commands["edge"] = { "edge {from} {to} {capacity}", std::bind(&Interp::action_add_edge, interp) };
    commands["clear"] = { "clear", std::bind(&Interp::action_clear_flow, interp) };
    commands["solve"] = { "solve {source} {sink}", std::bind(&Interp::action_solve, interp) };
}