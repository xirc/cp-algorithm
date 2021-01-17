#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/algebra/binexp.hpp"

using namespace std;

// a ^ b
// O(logN)
int64_t pow(int64_t a, int b) {
    return binexp<int64_t>(a, b, 1);
}

void action_eval() {
    int a, b;
    cin >> a >> b;
    if (b < 0) {
        cout << "false" << endl;
        return;
    }
    auto ans = pow(a, b);
    cout << ans << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Binary Exponentiation";
    commands["eval"] =
        Command { "eval {a} {b}", action_eval };
}