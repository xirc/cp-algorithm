#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/algebra/lcm.hpp"

// Compute GCD(a,b)
// Time: O( log(min(a,b)) )

using namespace std;

void action_eval() {
    int64_t a, b;
    cin >> a >> b;
    int64_t ans = lcm(a, b);
    cout << ans << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "lcm(a,b)";
    commands["lcm"] =
        Command { "lcm {a} {b}", action_eval };
}