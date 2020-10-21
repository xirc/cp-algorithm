#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll f(ll v) {
    if (v % 2) {
        ll u = (v + 1) / 2;
        return u % 2;
    } else {
        ll u = v / 2;
        return v + u % 2;
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