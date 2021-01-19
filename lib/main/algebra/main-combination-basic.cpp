#include <bits/stdc++.h>
#include "template/template-main.hpp"
#include "cpalgo/algebra/combination_basic.hpp"
#include "./template-combination-interp.hpp"

using namespace std;

CombinationBasic solver;

void setup(string& header, map<string,Command>& commands) {
    header = "Binomial Coefficient";
    commands["init"] =
        Command { "init {N} {MOD}", bind(action_init<CombinationBasic>, solver) };
    commands["eval"] =
        Command { "eval {n} {k}", bind(action_eval<CombinationBasic>, solver) };
}