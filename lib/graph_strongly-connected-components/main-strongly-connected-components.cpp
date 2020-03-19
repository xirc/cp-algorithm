#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include "../template-main.hpp"
#include "./strongly-connected-components.hpp"

using namespace std;

SCC solver(0);

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = SCC(size);
    cout << "true" << endl;
}

void action_edge() {
    int from, to;
    cin >> from >> to;
    if (from < 0 || from >= solver.size() ||
        to < 0 || to >= solver.size())
    {
        cout << "false" << endl;
        return;
    }
    solver.add_edge(from, to);
    cout << "true" << endl;
}

void action_solve() {
    auto ans = solver.solve();
    int w = log10(max(1,solver.size())) + 2;
    cout << "i: ";
    for (int v = 0; v < ans.size(); ++v) {
        if (v > 0) cout << " ";
        cout << v;
    }
    cout << endl;
    cout << "c: ";
    for (int v = 0; v < ans.size(); ++v) {
        if (v > 0) cout << " ";
        cout << ans[v];
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Strongly Connected Components";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {from} {to}", action_edge };
    commands["solve"] = { "solve", action_solve };
}