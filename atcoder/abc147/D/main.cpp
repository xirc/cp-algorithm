#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<ll> A;

int solve() {
    int const M = 64;
    ll const MOD = 1e9+7;
    ll ans = 0;
    for (int j = 0; j < M; ++j) {
        ll m = ll(1) << j;
        int zeros = 0, ones = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] & m) ++ones;
            else ++zeros;
        }
        ans += ((m % MOD) * zeros % MOD) * ones % MOD;
        ans %= MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}