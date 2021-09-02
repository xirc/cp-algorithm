#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll X, Y;
    ll A, B;

    cin >> X >> Y >> A >> B;

    ll exp = 0;
    while (X <= (Y-1) / A && X <= (X + B) / A) {
        X *= A;
        exp++;
    }
    exp += (Y - 1 - X) / B;
    cout << exp << endl;

    return 0;
}