#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll gcd(ll a, ll b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll num_divisable(ll n, ll b) {
    return n / b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    ll E = lcm(C, D);
    ll ans = B - A + 1;
    ans -= num_divisable(B, C) - num_divisable(A - 1, C);
    ans -= num_divisable(B, D) - num_divisable(A - 1, D);
    ans += num_divisable(B, E) - num_divisable(A - 1, E);
    cout << ans << endl;

    return 0;
}