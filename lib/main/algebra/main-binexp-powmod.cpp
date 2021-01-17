#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/algebra/binexp.hpp"

using namespace std;

// Compute (x^n) mod m
// O(logN)
int64_t powmod(int64_t x, int64_t n, int64_t m) {
    return binexp<int64_t>(x, n, 1, [&](auto const& lhs, auto const& rhs) {
        return (lhs * rhs) % m;
    });
}

void action_eval() {
    int64_t x, n, m;
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