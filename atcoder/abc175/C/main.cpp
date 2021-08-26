#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(ll X, ll K, ll D) {
    X = abs(X);
    ll p = X / D;
    p = min(p, K);
    X -= p * D;
    K -= p;

    K %= 2;
    if (K == 1) {
        X = abs(X - D);
    }
    return X;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll X, K, D;
    cin >> X >> K >> D;
    cout << solve(X, K, D) << endl;

    return 0;
}