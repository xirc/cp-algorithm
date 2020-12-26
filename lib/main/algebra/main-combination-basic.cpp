#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/algebra/combination_basic.hpp"

using namespace std;

Combination solver;

void action_init() {
    int N, MOD;
    cin >> N >> MOD;
    if (N < 2) {
        cout << "false" << endl;
        return;
    }
    solver = Combination(N, MOD);
}

void action_eval() {
    int n, k;
    cin >> n >> k;
    if (k < 0 || n < 0 || n >= solver.size() || n < k) {
        cout << "false" << endl;
        return;
    }
    auto ans = solver(n, k);
    cout << ans << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binomial Coefficient";
    commands["init"] =
        Command { "init {N} {MOD}", action_init };
    commands["eval"] =
        Command { "eval {n} {k}", action_eval };
}