#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

// inputs
int N, K;
vector<int> L, R;

// solution
int const MOD = 998244353;
ll plusf(ll lhs, ll rhs) {
    ll value = (lhs + rhs) % MOD;
    if (value < 0) value += MOD;
    return value;
}
ll minusf(ll lhs, ll rhs) {
    ll value = (lhs - rhs) % MOD;
    if (value < 0) value += MOD;
    return value;
}
ll solve() {
    vector<ll> f(N+1, 0);
    vector<ll> g(N+1, 0);
    f[0] = 1;
    for (int i = 0; i < N; ++i) {
        if (i > 0) g[i] = plusf(g[i], g[i-1]);
        f[i] = plusf(f[i], g[i]);
        for (int j = 0; j < K; ++j) {
            int l = i + L[j], r = i + R[j] + 1;
            if (l >= N) continue;
            r = min(r, N);
            ll p = f[i];
            g[l] = plusf(g[l], p);
            g[r] = minusf(g[r], p);
        }
    }
    return f[N-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    L.assign(K, 0);
    R.assign(K, 0);
    for (int i = 0; i < K; ++i) {
        cin >> L[i] >> R[i];
    }
    cout << solve() << endl;

    return 0;
}