#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/tree/lowest-common-ancestor/lca-tarjan.hpp"

using namespace std;

LCA lca;
vector<vector<int>> adj;

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    adj.assign(size, vector<int>());
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
    cout << "true" << endl;
}

void action_solve() {
    const int N = adj.size();
    int Q;
    cin >> Q;
    if (Q < 0) {
        cout << "false" << endl;
        return;
    }
    vector<pair<int,int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= N ||
            v < 0 || v >= N)
        {
            cout << "false" << endl;
            return;
        }
        queries[i] = { u, v };
    }
    auto ans = lca.solve(adj, queries);
    for (int i = 0; i < Q; ++i) {
        cout << queries[i].first << " " << queries[i].second << ": " << ans[i] << endl;
    }
}


void setup(string& header, map<string,Command>& commands) {
    header = "LCA offline";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {u} {v}", action_edge };
    commands["solve"] = { "solve Q {u v}...", action_solve };
}