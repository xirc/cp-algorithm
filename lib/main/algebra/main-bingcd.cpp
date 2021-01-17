#include <iostream>
#include "../template-main.hpp"
#include "bingcd.hpp"

// Compute Binary GCD(a,b)
// Time: O( log(min(a,b)) )

using namespace std;

void action_eval() {
    int64_t a, b;
    cin >> a >> b;
    int64_t ans = gcd(a, b);
    cout << ans << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "gcd(a,b)";
    commands["gcd"] =
        Command { "gcd {a} {b}", action_eval };
}