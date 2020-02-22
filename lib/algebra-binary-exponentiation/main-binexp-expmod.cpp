#include <iostream>
#include "../template-main.hpp"

using namespace std;

// Compute (x^n) mod m
long long powmod(long long x, long long n, long long m) {
    x %= m;
    long long ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * x) % m;
        }
        x = (x * x) % m;
        n >>= 1;
    }
    return ans;
}

void action_eval() {
    long long x, n, m;
    cin >> x >> n >> m;
    if (n < 0 || m <= 0) {
        cout << "false" << endl;
        return;
    }
    cout << powmod(x, n, m) << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "(x^n) mod m";
    commands["eval"] =
        Command { "eval {x} {n} {m}", action_eval };
}