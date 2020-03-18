#include <iostream>
#include <iomanip>
#include <cmath>
#include "../template-main.hpp"
#include "./heavy-light-decomposition.hpp"

using namespace std;

using HLD = shared_ptr<HeavyLightDecomposition>;
vector<vector<int>> adj;
HLD solver = nullptr;

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    adj.assign(size, vector<int>());
    solver = nullptr;
    cout << "true" << endl;
}

void action_edge() {
    const int N = adj.size();
    int u, v;
    cin >> u >> v;
    if (u < 0 || u >= N ||
        v < 0 || v >= N)
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
    const int N = adj.size();
    int u, v;
    cin >> u >> v;
    if (u < 0 || u >= N ||
        v < 0 || v >= N)
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
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << setw(floor(log10(N))+1) << i;
    }
    cout << endl;

    cout << "vertex: ";
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << setw(floor(log10(N))+1) << solver->get_vertex(i);
    }
    cout << endl;

    cout << "ForEach-SubtreeVertex:";
    solver->for_each_subtree_vertex(u, [&](int l, int r) { cout << " u:(" << l << "," << r << ")"; });
    solver->for_each_subtree_vertex(v, [&](int l, int r) { cout << " v:(" << l << "," << r << ")"; });
    cout << endl;

    cout << "ForEach-SubtreeEdge:";
    solver->for_each_subtree_edge(u, [&](int l, int r) { cout << " u:(" << l << "," << r << ")"; });
    solver->for_each_subtree_edge(v, [&](int l, int r) { cout << " v:(" << l << "," << r << ")"; });
    cout << endl;

    cout << "ForEach-Vertex:";
    solver->for_each_vertex(u, v, [&](int l, int r) { cout << " (" << l << "," << r << ")"; });
    cout << endl;

    cout << "ForEach-Edge:";
    solver->for_each_edge(u, v, [&](int l, int r) { cout << " (" << l << "," << r << ")"; });
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Heavy Light Decomposition";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {u} {v}", action_edge };
    commands["query"] = { "query {u} {v}", action_query };
}