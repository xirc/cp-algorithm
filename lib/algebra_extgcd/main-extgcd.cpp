#include <bits/stdc++.h>
#include "../template-main.hpp"
#include "extgcd.hpp"

// Compute Extended Euculidean Algorithm
// Time: O( log(min(a,b)) )

using namespace std;

void putinfo(long long a, long long b, long long x, long long y, long long g) {
    cout << a << " x + " << b << " y = gcd(" << a << "," << b << ")" << endl;
    cout << "x = " << x << ", y = " << y << ", gcd(a,b) = " << g << endl;
}

void action_extgcd() {
    long long a, b, x, y, g;
    cin >> a >> b;
    g = extgcd(a, b, x, y);
    putinfo(a, b, x, y, g);
}

void action_extgcdi() {
    long long a, b, x, y, g;
    cin >> a >> b;
    g = extgcdi(a, b, x, y);
    putinfo(a, b, x, y, g);
}

void setup(string& header, map<string,Command>& commands) {
    header = "Extended Euclidean Algorithm";
    commands["extgcd"] =
        Command { "extgcd {a} {b}", action_extgcd };
    commands["extgcdi"] =
        Command { "extgcdi {a} {b}", action_extgcdi };
}