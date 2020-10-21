#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll base(ll v) {
    assert(v >= 1);
    ll b = 1;
    while (v >= b * 2) {
        b *= 2;
    }
    return b;
}

ll f(ll v) {
    if (v == 0) return 0;
    if (v == 1) return 1;
    if (v == 2) return 3;
    ll m = base(v);
    if (m == v) return m;
    if (v == 2 * m - 1) return 0;
    ll u = v - m;
    if (u % 2) {
        return f(u);
    } else {
        return m ^ f(u);
    }
}

ll solve(ll A, ll B) {
    if (A == 0) return f(B);
    return f(B) ^ f(A-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll A, B;
    cin >> A >> B;
    cout << solve(A, B) << endl;

    return 0;
}