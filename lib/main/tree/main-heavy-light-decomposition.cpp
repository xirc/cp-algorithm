#include <iostream>
#include <iomanip>
#include <cmath>
#include <memory>
#include "template/template-main.hpp"
#include "cpalgo/tree/heavy_light_decomposition.hpp"

using namespace std;

using HLD = shared_ptr<HeavyLightDecomposition>;
vector<vector<size_t>> adj;
HLD solver = nullptr;

void action_init() {
    size_t size;
    cin >> size;
    adj.assign(size, vector<size_t>());
    solver = nullptr;
    cout << "true" << endl;
}

void action_edge() {
    const size_t N = adj.size();
    size_t u, v;
    cin >> u >> v;
    if (u >= N || v >= N)
    {
        cout << "false" << endl;
        return;
    }
    adj[u].push_back(v);
    adj[v].push_back(u);
    solver = nullptr;
    cout << "true" << endl;
}

void action_query() {
    const size_t N = adj.size();
    size_t u, v;
    cin >> u >> v;
    if (u >= N || v >= N)
    {
        cout << "false" << endl;
        return;
    }

    if (!solver) {
        solver = HLD(new HeavyLightDecomposition(adj, {0}));
    }

    cout << "LCA: " << solver->lca(u, v) << endl;
    cout << "Distance: " << solver->distance(u, v) << endl;

    cout << "index:  ";
    for (size_t i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << setw(floor(log10(N))+1) << i;
    }
    cout << endl;

    cout << "vertex: ";
    for (size_t i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << setw(floor(log10(N))+1) << solver->get_vertex(i);
    }
    cout << endl;

    cout << "ForSubtreeVertex:";
    solver->for_subtree_vertex(u, [&](size_t l, size_t r) { cout << " u:(" << l << "," << r << ")"; });
    solver->for_subtree_vertex(v, [&](size_t l, size_t r) { cout << " v:(" << l << "," << r << ")"; });
    cout << endl;

    cout << "ForSubtreeEdge:";
    solver->for_subtree_edge(u, [&](size_t l, size_t r) { cout << " u:(" << l << "," << r << ")"; });
    solver->for_subtree_edge(v, [&](size_t l, size_t r) { cout << " v:(" << l << "," << r << ")"; });
    cout << endl;

    cout << "ForEachVertex:";
    solver->for_each_vertex(u, v, [&](size_t l, size_t r, bool reverse) { cout << " (" << l << "," << r << "," << (reverse ? "r" : "f") << ")"; });
    cout << endl;

    cout << "ForEachEdge:";
    solver->for_each_edge(u, v, [&](size_t l, size_t r, bool reverse) { cout << " (" << l << "," << r << "," << (reverse ? "r" : "f") << ")"; });
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Heavy Light Decomposition";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {u} {v}", action_edge };
    commands["query"] = { "query {u} {v}", action_query };
}