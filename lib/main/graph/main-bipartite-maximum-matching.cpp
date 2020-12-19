#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/graph/bipartite-maximum-matching.hpp"

using namespace std;

BipartiteMaximumMatching solver;

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = BipartiteMaximumMatching(size);
    cout << "true" << endl;
}

void action_edge() {
    int u, v;
    cin >> u >> v;
    if (u < 0 || u >= solver.size() ||
        v < 0 || v >= solver.size())
    {
        cout << "false" << endl;
        return;
    }
    solver.add_edge(u, v);
    cout << "true" << endl;
}

void action_solve() {
    vector<int> match;
    int ans = solver.solve(match);
    cout << ans << endl;
    for (int i = 0; i < match.size(); ++i) {
        cout << i << ": " << match[i] << endl;
    }
}

void setup(string& header, map<string,Command>& commands) {
    header = "Bipartite Maximum Matching";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {u} {v}", action_edge };
    commands["solve"] = { "solve", action_solve };
}