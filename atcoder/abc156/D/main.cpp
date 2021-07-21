#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll const MOD = 1e9 + 7;

ll binexp(ll b, int e) {
    if (e == 0) return 1;
    ll h = binexp(b, e / 2);
    ll ans = h * h % MOD;
    if (e % 2 == 1) ans = ans * b % MOD;
    return ans;
}

vector<ll> factorial_inverse, inverse, combination;
void init_combination(int n, int K) {
    factorial_inverse.assign(K + 1, 0);
    inverse.assign(K + 1, 0);
    combination.assign(K + 1, 0);
    factorial_inverse[0] = factorial_inverse[1] = 1;
    inverse[1] = 1;
    for (int i = 2; i < K + 1; ++i) {
        inverse[i] = MOD - inverse[MOD % i] * (MOD / i) % MOD;
        factorial_inverse[i] = factorial_inverse[i-1] * inverse[i] % MOD;
    }
    combination[0] = 1;
    for (int i = 1; i < K + 1; ++i) {
        combination[i] = combination[i-1] * ((n - i + 1) * inverse[i] % MOD) % MOD;
    }
}

ll calc_combination(int k) {
    return combination[k];
}

ll solve(int n, int a, int b) {
    ll S = binexp(2, n) - 1;
    if (S < 0) S += MOD;
    init_combination(n, max(a,b));
    ll A = calc_combination(a);
    ll B = calc_combination(b);
    ll U = S - A;
    if (U < 0) U += MOD;
    U = U - B;
    if (U < 0) U += MOD;
    return U;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    cout << solve(n, a, b) << endl;

    return 0;
}