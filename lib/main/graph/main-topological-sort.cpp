#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/graph/topological-sort.hpp"

using namespace std;

TopologicalSort solver;

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = TopologicalSort(size);
    cout << "true" << endl;
}

void action_add_edge() {
    int from, to;
    cin >> from >> to;
    if (from < 0 || from >= solver.size() ||
        to < 0 || to >= solver.size())
    {
        cout << "false" << endl;
        return;
    }
    solver.add_edge(from, to);
}

void action_solve() {
    std::vector<int> ans;
    auto has_ans = solver.solve(ans);
    if (!has_ans) {
        cout << "false" << endl;
        return;
    }
    for (int i = 0; i < ans.size(); ++i) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "topological sort";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {from} {to}", action_add_edge };
    commands["solve"] = { "solve", action_solve };
}