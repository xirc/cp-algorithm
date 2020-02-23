#include <iostream>
#include "../template-main.hpp"
#include "./binexp.hpp"

using namespace std;

// O(logN)
long long binpow(long long a, int b) {
    return binpow<long long>(a, b, 1);
}

void action_eval() {
    int a, b;
    cin >> a >> b;
    if (b < 0) {
        cout << "false" << endl;
        return;
    }
    cout << binpow(a, b) << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binary Exponentiation";
    commands["eval"] =
        Command { "eval {a} {b}", action_eval };
}