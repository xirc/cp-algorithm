#include <map>
#include <string>
#include <memory>
#include "../template-main.hpp"
#include "./floyd-warshall.hpp"

using namespace std;

using SolverPtr = shared_ptr<FloydWarshall>;
SolverPtr solver = SolverPtr(new FloydWarshall(0));

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = SolverPtr(new FloydWarshall(size));
    cout << "true" << endl;
}

void action_add_edge() {
    int from, to, cost;
    cin >> from >> to >> cost;
    if (from < 0 || from >= solver->size() ||
        to < 0 || to >= solver->size())
    {
        cout << "false" << endl;
        return;
    }
    solver->add_edge(from, to, cost);
    cout << "true" << endl;
}

void action_solve() {
    vector<pair<int,int>> ans;
    solver->solve(ans);
    for (int i = 0; i < ans.size(); ++i) {
        if (i > 0) cout << " ";
        cout << "(" << ans[i].first << "," << ans[i].second << ")";
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Negatice Cycle Finding with BellmanFord";
    commands["init"] = { "init {size}", action_init };
    commands["add-edge"] = { "add-edge {from} {to} {cost}", action_add_edge };
    commands["solve"] = { "solve", action_solve };
}