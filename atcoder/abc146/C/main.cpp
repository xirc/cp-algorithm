#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll A, B, X;

int dig(ll n) {
    int d = 0;
    while (n > 0) {
        ++d;
        n /= 10;
    }
    return d;
}

bool can_buy(ll n) {
    if (n > 1000000000) return false;
    return A * n + B * dig(n) <= X;
}

ll solve() {
    if (X < A + B) return 0;
    ll ng = 1000000001, ok = 1;
    while (abs(ng - ok) > 1) {
        ll m = (ng + ok) >> 1;
        if (can_buy(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A >> B >> X;
    cout << solve() << endl;

    return 0;
}