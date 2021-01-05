#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string solve(ll X, ll Y) {
    ll Z = abs(X - Y);
    return Z <= 1 ? "Brown" : "Alice";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll X, Y;
    cin >> X >> Y;
    cout << solve(X, Y) << endl;

    return 0;
}