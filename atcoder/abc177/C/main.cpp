#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<ll> A;

    cin >> N;
    A.assign(N, 0);
    for (auto &x : A) cin >> x;

    for (int i = 1; i < N; ++i) {
        A[i] += A[i-1];
    }

    ll const MOD = 1e9 + 7;
    ll ans = 0;
    for (int i = 1; i < N; ++i) {
        ll x = A[i] - A[i-1];
        ans += x * (A[i-1] % MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}