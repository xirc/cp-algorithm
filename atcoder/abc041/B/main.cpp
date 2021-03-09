#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll MOD = 1e9+7;
    ll A, B, C;
    cin >> A >> B >> C;
    ll X = (A * ((B * C) % MOD)) % MOD;
    cout << X << endl;

    return 0;
}