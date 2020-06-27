#include "../template-main.hpp"
#include "./extended-euclidean.hpp"

using namespace std;

void action_solve() {
    long long a, b, x, y;
    cin >> a >> b;
    extended_gcd(a, b, x, y);
    cout << a << " x + " << b << " y = gcd(" << a << "," << b << ")" << endl;
    cout << "x = " << x << ", y = " << y << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Extended Euclidean Algorithm";
    commands["solve"] = { "solve {a} {b}", action_solve };
}