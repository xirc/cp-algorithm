#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/graph/bipartite-maximum-matching.hpp"

using namespace std;

BipartiteMaximumMatching solver;

void action_init() {
    size_t size;
    cin >> size;
    solver = BipartiteMaximumMatching(size);
    cout << "true" << endl;
}

void action_edge() {
    size_t u, v;
    cin >> u >> v;
    if (u >= solver.size() ||
        v >= solver.size())
    {
        cout << "false" << endl;
        return;
    }
    solver.add_edge(u, v);
    cout << "true" << endl;
}

void action_solve() {
    vector<size_t> match;
    size_t ans = solver.solve(match);
    cout << ans << endl;
    for (size_t i = 0; i < match.size(); ++i) {
        cout << i << ": " << match[i] << endl;
    }
}

void setup(string& header, map<string,Command>& commands) {
    header = "Bipartite Maximum Matching";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {u} {v}", action_edge };
    commands["solve"] = { "solve", action_solve };
}