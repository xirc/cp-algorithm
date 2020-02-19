#include <map>
#include <string>
#include "../template-main.hpp"
#include "./bellman-ford.hpp"

using namespace std;

using SolverPtr = shared_ptr<BellmanFord>;
SolverPtr solver = SolverPtr(new BellmanFord(0));

void action_init() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    solver = SolverPtr(new BellmanFord(size));
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
    int from;
    vector<int> ans;
    cin >> from;
    if (from < 0 || from >= solver->size()) {
        cout << "false" << endl;
        return;
    }
    auto has_ans = solver->solve(ans);
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
    header = "Negatice Cycle Finding with BellmanFord";
    commands["init"] =
        Command { "init {size}", action_init };
    commands["add-edge"] =
        Command { "add-edge {from} {to} {cost}", action_add_edge };
    commands["solve"] =
        Command { "solve {from}", action_solve };
}