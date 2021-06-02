#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll const MOD = 1e9 + 7;

int N;
vector<ll> A;

ll solve(string const& L, int i) {
    if (i == L.size()) return 1;
    if (L[i] == '0') {
        return solve(L, i + 1);
    }
    ll ans = 0;
    int n = N - 1 - i;
    ans += A[n] % MOD;
    ans %= MOD;
    ans += 2 * solve(L, i + 1) % MOD;
    ans %= MOD;
    return ans;
}

ll solve(string const& L) {
    N = L.size();
    A.assign(N, 0);
    A[0] = 1;
    ll acc = A[0];
    for (int i = 1; i < N; ++i) {
        A[i] = 2 * acc % MOD;
        acc = (acc + A[i]) % MOD;
    }
    for (int i = 1; i < N; ++i) {
        A[i] = (A[i] + A[i-1]) % MOD;
    }
    return solve(L, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string L;
    cin >> L;
    cout << solve(L) << endl;

    return 0;
}