#include <bits/stdc++.h>
#include "template/template-main.hpp"
#include "cpalgo/algebra/combination_basic.hpp"

using namespace std;

CombinationBasic<> solver;

void action_init() {
    size_t N;
    std::cin >> N;
    solver = CombinationBasic<>(N);
}

void action_eval_C() {
    size_t n, k;
    std::cin >> n >> k;
    if (n > solver.size() || n < k) {
        std::cout << "false" << std::endl;
        return;
    }
    auto ans = solver.C(n, k);
    std::cout << ans << std::endl;
}

void action_eval_P() {
    size_t n, k;
    std::cin >> n >> k;
    if (n > solver.size() || n < k) {
        std::cout << "false" << std::endl;
        return;
    }
    auto ans = solver.P(n, k);
    std::cout << ans << std::endl;
}

void action_eval_H() {
    size_t n, k;
    std::cin >> n >> k;
    if ((n == 0 && k > 0) || (n > 0 && n + k - 1 > solver.size())) {
        std::cout << "false" << std::endl;
        return;
    }
    auto ans = solver.H(n, k);
    std::cout << ans << std::endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binomial Coefficient in modulo";
    commands["init"] =
        Command { "init {N}", action_init };
    commands["C"] =
        Command { "C {n} {k}", action_eval_C };
    commands["P"] =
        Command { "P {n} {k}", action_eval_P };
    commands["H"] =
        Command { "H {n} {k}", action_eval_H };
}
