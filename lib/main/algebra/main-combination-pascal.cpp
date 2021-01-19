#include <bits/stdc++.h>
#include "template/template-main.hpp"
#include "cpalgo/algebra/combination_pascal.hpp"
#include "./template-combination-interp.hpp"

using namespace std;

CombinationPascal solver;

void setup(string& header, map<string,Command>& commands) {
    header = "Binomial Coefficient that uses Pascal's Triangle";
    commands["init"] =
        Command { "init {N} {MOD}", bind(action_init<CombinationPascal>, solver) };
    commands["eval"] =
        Command { "eval {n} {k}", bind(action_eval<CombinationPascal>, solver) };
}