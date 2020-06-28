#include <iostream>
#include "../template-main.hpp"
#include "./binexp.hpp"

using namespace std;

// (a * b) mod m
// O(logN)
long long mulmod(long long a, long long b, long long m) {
    return binexp<long long>(a, b, 0, [&](auto const& lhs, auto const& rhs){
        return (lhs + rhs) % m;
    });
}

void action_eval() {
    long long a, b, m;
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