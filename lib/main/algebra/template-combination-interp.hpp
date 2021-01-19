#pragma once

#include <iostream>

template <class Combination>
void action_init(Combination &solver) {
    size_t N;
    uint64_t MOD;
    std::cin >> N >> MOD;
    if (N < 2) {
        std::cout << "false" << std::endl;
        return;
    }
    solver = Combination(N, MOD);
}

template <class Combination>
void action_eval(Combination &solver) {
    size_t n, k;
    std::cin >> n >> k;
    if (n >= solver.size() || n < k) {
        std::cout << "false" << std::endl;
        return;
    }
    auto ans = solver(n, k);
    std::cout << ans << std::endl;
}