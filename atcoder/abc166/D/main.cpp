#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

void solve(ll X) {
    for (ll a = -200; a <= 200; ++a) {
        for (ll b = -200; b <= 200; ++b) {
            ll s1 = a * a * a * a * a - b * b * b * b * b;
            if (s1 == X) {
                cout << a << " " << b << endl;
                return;
            }
        }
    }
    throw;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll X;
    cin >> X;
    solve(X);

    return 0;
}