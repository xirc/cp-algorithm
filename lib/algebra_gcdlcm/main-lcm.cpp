#include <iostream>
#include "../template-main.hpp"
#include "gcdlcm.hpp"

// Compute GCD(a,b)
// Time: O( log(min(a,b)) )

using namespace std;

void action_eval() {
    long long a, b;
    cin >> a >> b;
    long long ans = lcm(a, b);
    cout << ans << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "lcm(a,b)";
    commands["lcm"] =
        Command { "lcm {a} {b}", action_eval };
}