#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using lf = long double;

inline ll floori(ll x) {
    if (x >= 0) return x / 10000;
    else return (x - 9999) / 10000;

}
inline ll ceili(ll x) {
    if (x >= 0) return (x + 9999) / 10000;
    else return x / 10000;
}

ll solve(ll X, ll Y, ll R) {
    ll lx = ((X - R) / 10000 - 1) * 10000;
    ll rx = ((X + R) / 10000 + 1) * 10000;
    assert(lx <= X - R);
    assert(rx >= X + R);

    ll ans = 0;
    for (ll x = lx; x <= rx; x += 10000) {
        assert(x % 10000 == 0);
        ll K = abs(x - X);
        if (K > R) continue;
        ll Z2 = R * R - K * K;
        ll Z = floor(sqrtl(Z2));
        ll uY = floori(Y + Z);
        ll bY = ceili(Y - Z);
        ans += (uY - bY + 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    lf X, Y, R;
    cin >> X >> Y >> R;
    ll iX = (ll)round(X * 10000);
    ll iY = (ll)round(Y * 10000);
    ll iR = (ll)round(R * 10000);
    cout << solve(iX, iY, iR) << endl;

    return 0;
}