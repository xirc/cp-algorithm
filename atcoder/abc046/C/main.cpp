#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    ll a, b;
    a = 1, b = 1;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int T, A;
        cin >> T >> A;
        if (a * A == b * T) continue;
        ll u = (a + T - 1) / T;
        ll v = (b + A - 1) / A;
        ll k = max(u, v);
        a = k * T;
        b = k * A;
    }
    cout << (a + b) << endl;

    return 0;
}