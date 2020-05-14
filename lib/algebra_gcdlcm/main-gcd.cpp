#include <iostream>
#include "../template-main.hpp"
#include "gcdlcm.hpp"

// Compute GCD(a,b)
// Time: O( log(min(a,b)) )

using namespace std;

void action_eval() {
    long long a, b;
    cin >> a >> b;
    long long ans = gcd(a, b);
    cout << ans << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "gcd(a,b)";
    commands["gcd"] =
        Command { "gcd {a} {b}", action_eval };
}