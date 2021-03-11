#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll count(ll n, ll x) {
    if (n < 0) return 0;
    return n / x + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll a, b, x;
    cin >> a >> b >> x;

    ll l = count(a - 1, x);
    ll r = count(b, x);
    cout << r - l << endl;

    return 0;
}