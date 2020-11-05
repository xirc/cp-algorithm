#include <iostream>
#include "../template-main.hpp"
#include "prime-factorization-basic.hpp"

using namespace std;

void action_eval() {
    long long n;
    cin >> n;
    auto ans = prime_factorization(n);
    for (auto f : ans) {
        auto b = f.first;
        auto e = f.second;
        cout << b << " ** " << e << endl;
    }
}

void setup(string& header, map<string,Command>& commands) {
    header = "Prime Factorization";
    commands["solve"] =
        Command { "solve {n}", action_eval };
}