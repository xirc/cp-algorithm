#include <bits/stdc++.h>
#include "template/template-main.hpp"
#include "cpalgo/tree/lowest-common-ancestor/lca-tarjan.hpp"

using namespace std;


vector<vector<size_t>> adj;

void action_init() {
    size_t size;
    cin >> size;
    adj.assign(size, vector<size_t>());
}

void action_edge() {
    size_t u, v;
    cin >> u >> v;
    if (u >= adj.size() ||
        v >= adj.size())
    {
        cout << "false" << endl;
        return;
    }
    adj[u].push_back(v);
    adj[v].push_back(u);
    cout << "true" << endl;
}

void action_solve() {
    size_t Q;
    cin >> Q;
    vector<pair<size_t,size_t>> queries(Q);
    for (size_t i = 0; i < Q; ++i) {
        size_t u, v;
        cin >> u >> v;
        if (u >= adj.size() ||
            v >= adj.size())
        {
            cout << "false" << endl;
            return;
        }
        queries[i] = { u, v };
    }
    auto ans = lca(adj, queries);
    for (size_t i = 0; i < Q; ++i) {
        cout << queries[i].first << " " << queries[i].second << ": " << ans[i] << endl;
    }
}


void setup(string& header, map<string,Command>& commands) {
    header = "LCA offline";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {u} {v}", action_edge };
    commands["solve"] = { "solve Q {u v}...", action_solve };
}