#include <bits/stdc++.h>
#include "template/template-main.hpp"
#include "cpalgo/tree/euler-tour.hpp"

using namespace std;


EulerTour solver;

void action_init() {
    size_t size;
    cin >> size;
    solver = EulerTour(size);
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
    const size_t N = solver.size();
    size_t r;
    cin >> r;
    if (r >= N) {
        cout << "false" << endl;
        return;
    }
    vector<size_t> tour, tin, tout;
    solver.solve(r, tour, tin, tout);
    const size_t W = log10(max(size_t(1),N)) + 2;
    auto dump = [&](string const& header, vector<size_t> const& v) {
        cout << header;
        for (size_t i = 0; i < v.size(); ++i) {
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
    commands["solve"] = { "solve {r}", action_solve };
}