#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/algebra/combination_basic.hpp"

using namespace std;

Combination solver;

void action_init() {
    size_t N;
    uint64_t MOD;
    cin >> N >> MOD;
    if (N < 2) {
        cout << "false" << endl;
        return;
    }
    solver = Combination(N, MOD);
}

void action_eval() {
    size_t n, k;
    cin >> n >> k;
    if (n >= solver.size() || n < k) {
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