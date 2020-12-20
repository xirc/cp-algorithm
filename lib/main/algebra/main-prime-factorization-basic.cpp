#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/algebra/prime-factorization-basic.hpp"

using namespace std;

void action_eval() {
    long long n;
    cin >> n;
    auto factors = prime_factorization(n);
    for (size_t i = 0; i < factors.size(); ++i) {
        if (i > 0) cout << " * ";
        cout << factors[i];
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Prime Factorization";
    commands["solve"] =
        Command { "solve {n}", action_eval };
}