#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int solve(int const N, string const& S) {
    int const M = 10;
    int const L = 1 << M;
    ll const MOD = 998244353;

    vector<vector<ll>> Dc(M, vector<ll>(L, 0));
    vector<vector<ll>> Dn(M, vector<ll>(L, 0));

    for (int i = 0; i < N; ++i) {
        int const c = S[i] - 'A';
        // Clear
        for (int e = 0; e < M; ++e) {
            fill(Dn[e].begin(), Dn[e].end(), 0);
        }
        // Pick this char with an empty sequence
        Dn[c][(1<<c)] += 1;
        Dn[c][(1<<c)] %= MOD;
        for (int s = 0; s < L; ++s) {
            for (int e = 0; e < M; ++e) {
                // Not pick this char
                Dn[e][s] += Dc[e][s];
                Dn[e][s] %= MOD;
                // Pick this char when the previous one is the same.
                if (e == c) {
                    Dn[e][s] += Dc[e][s];
                    Dn[e][s] %= MOD;
                }
            }
            if ((s&(1<<c)) == 0) {
                // Pick this char when the previous one is not the same.
                for (int e = 0; e < M; ++e) {
                    Dn[c][s|(1<<c)] += Dc[e][s];
                    Dn[c][s|(1<<c)] %= MOD;
                }
            }
        }
        swap(Dn, Dc);
    }

    ll ans = 0;
    for (int c = 0; c < M; ++c) {
        for (int s = 0; s < L; ++s) {
            ans += Dc[c][s];
            ans %= MOD;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    string S;
    cin >> N >> S;
    cout << solve(N, S) << endl;

    return 0;
}