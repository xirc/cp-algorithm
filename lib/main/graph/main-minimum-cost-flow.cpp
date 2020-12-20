#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/graph/minimum-cost-flow.hpp"

using namespace std;

MinimumCostFlow solver;

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = MinimumCostFlow(size);
    cout << "true" << endl;
}

void action_add_edge() {
    int from, to;
    long long capacity, cost;
    cin >> from >> to >> capacity >> cost;
    if (from < 0 || from >= solver.size() ||
        to < 0 || to >= solver.size() ||
        capacity < 0
    ) {
        cout << "false" << endl;
        return;
    }
    solver.add_edge(from, to, capacity, cost);
    cout << "true" << endl;
}

void action_solve() {
    int s, t;
    long long K;
    cin >> s >> t >> K;
    if (s < 0 || s >= solver.size() ||
        t < 0 || t >= solver.size()
    ) {
        cout << "false" << endl;
        return;
    }
    long long flow, cost;
    solver.solve(s, t, K, flow, cost);
    cout << flow << " " << cost << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Minimum Cost Flow";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {from} {to} {capacity} {cost}", action_add_edge };
    commands["solve"] = { "solve {source} {sink} {flow}", action_solve };
}