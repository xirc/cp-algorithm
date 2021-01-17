#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/algebra/binexp.hpp"

using namespace std;

// (a * b) mod m
// O(logN)
int64_t mulmod(int64_t a, int64_t b, int64_t m) {
    return binexp<int64_t>(a, b, 0, [&](auto const& lhs, auto const& rhs){
        return (lhs + rhs) % m;
    });
}

void action_eval() {
    int64_t a, b, m;
    cin >> a >> b >> m;
    if (m <= 0) {
        cout << "false" << endl;
        return;
    }
    cout << mulmod(a, b, m) << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "(a * b) mod m";
    commands["eval"] =
        Command { "eval {a} {b} {m}", action_eval };
}