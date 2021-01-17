#pragma once

#include <bits/stdc++.h>
#include "template/template-main.hpp"

void action_extgcd(std::function<uint64_t(uint64_t, uint64_t, int64_t&, int64_t&)> const& extgcd) {
    int64_t a, b, x, y, g;
    std::cin >> a >> b;

    g = extgcd(a, b, x, y);

    std::cout << a << " x + " << b << " y = gcd(" << a << "," << b << ")" << std::endl;
    std::cout << "x = " << x << ", y = " << y << ", gcd(a,b) = " << g << std::endl;
}

void setup(
    std::string& header,
    std::map<std::string,Command>& commands,
    std::function<uint64_t(uint64_t, uint64_t, int64_t&, int64_t&)> const& extgcd
) {
    commands["extgcd"] =
        Command { "extgcd {a} {b}", std::bind(action_extgcd, extgcd) };
}