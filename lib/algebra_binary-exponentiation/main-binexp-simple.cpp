#include <iostream>
#include "../template-main.hpp"
#include "./binexp.hpp"

using namespace std;

// a ^ b
// O(logN)
long long binexp(long long a, int b) {
    return binexp<long long>(a, b, 1);
}

void action_eval() {
    int a, b;
    cin >> a >> b;
    if (b < 0) {
        cout << "false" << endl;
        return;
    }
    cout << binexp(a, b) << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binary Exponentiation";
    commands["eval"] =
        Command { "eval {a} {b}", action_eval };
}