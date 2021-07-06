#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<ll> A;

int solve() {
    int const M = 64;
    ll const MOD = 1e9+7;
    vector<ll> T(M, 0);
    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N; ++i) {
            T[j] += A[i] & (ll(1) << j);
            T[j] %= MOD;
        }
    }
    vector<ll> S(N, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int b = (A[i] >> j) & 1;
            if (b == 0) {
                S[i] += T[j];
                S[i] %= MOD;
            }
        }
    }
    ll ss = 0;
    for (int i = 0; i < N; ++i) {
        ss += S[i];
        ss %= MOD;
    }
    return ss;
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