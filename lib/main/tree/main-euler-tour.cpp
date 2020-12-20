#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include "template/template-main.hpp"
#include "cpalgo/tree/euler-tour.hpp"

using namespace std;

EulerTrour solver;

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = EulerTrour(size);
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
    const int N = solver.size();
    int r;
    cin >> r;
    if (r < 0 || r >= N) {
        cout << "false" << endl;
        return;
    }
    vector<int> tour, tin, tout;
    solver.solve(r, tour, tin, tout);
    const int W = log10(max(1,N)) + 2;
    auto dump = [&](const string& header, const vector<int>& v) {
        cout << header;
        for (int i = 0; i < v.size(); ++i) {
            if (i > 0) cout << " ";
            cout << setw(W) << v[i];
        }
        cout << endl;
    };
    dump("tour: ", tour);
    dump("tin:  ", tin);
    dump("tout: ", tout);
}

void setup(string& header, map<string,Command>& commands) {
    header = "Euler Tour";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {u} {v}", action_edge };
    commands["solve"] = { "solve", action_solve };
}