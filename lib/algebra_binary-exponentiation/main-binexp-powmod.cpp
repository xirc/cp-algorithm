#include <iostream>
#include "../template-main.hpp"
#include "./binexp.hpp"

using namespace std;

// Compute (x^n) mod m
// O(logN)
long long powmod(long long x, long long n, long long m) {
    return binexp<long long>(x, n, 1, [&](auto const& lhs, auto const& rhs) {
        return (lhs * rhs) % m;
    });
}

void action_eval() {
    long long x, n, m;
    cin >> x >> n >> m;
    if (n < 0 || m <= 0) {
        cout << "false" << endl;
        return;
    }
    auto ans = powmod(x, n, m);
    cout << ans << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "(x^n) mod m";
    commands["eval"] =
        Command { "eval {x} {n} {m}", action_eval };
}