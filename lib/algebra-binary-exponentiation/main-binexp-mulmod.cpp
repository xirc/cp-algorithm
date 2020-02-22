#include <iostream>
#include "../template-main.hpp"

using namespace std;

// (a * b) mod m
long long mulmod(long long a, long long b, long long m) {
    if (a == 0) return 0;
    long long half = mulmod(a / 2, b, m);
    long long value = (half + half) % m;
    if (a & 1) {
        return (value + b) % m;
    } else {
        return value;
    }
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