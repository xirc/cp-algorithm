#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, D;
ll const MOD = 998244353;

ll solve() {
    vector<ll> bp(3000000, 0);
    bp[0] = 1;
    for (int i = 1; i < (int)bp.size(); ++i) {
        bp[i] = bp[i-1] * 2 % MOD;
    }

    auto const f = [&](int d) -> ll {
        if (d + D > N - 1) return 0;
        return bp[D+1];
    };
    auto const g = [&](int d) -> ll {
        if (D == 1) return 0;
        if (D > 2 * N - 2 * d - 2) return 0;
        if (d + D <= N - 1) return bp[D-1] * (D-1) % MOD;
        return bp[D-1] * (2 * N - 2 * d - D - 1) % MOD;
    };

    ll ans = 0;
    for (int d = 0; d <= N - 1; ++d) {
        ll fg = (f(d) + g(d)) % MOD;
        ll cfg = bp[d] * fg % MOD;
        ans += cfg;
        ans %= MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> D;
    cout << solve() << endl;

    return 0;
}