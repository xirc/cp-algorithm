#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
ll K;
vector<ll> A;

ll solve() {
    const int M = 62;
    auto B = vector<vector<ll>>(M, vector<ll>(2, 0));
    auto DP = vector<vector<ll>>(M, vector<ll>(2, 0));
    for (int e = 0; e < M; ++e) {
        int zeros = 0, ones = 0;
        for (int i = 0; i < N; ++i) {
            if ((A[i] >> e) & 1) ++ones;
            else ++zeros;
        }
        auto p = e > 0 ? max(DP[e-1][0], DP[e-1][1]) : 0L;
        B[e][0] = (1L << e) * ones;
        B[e][1] = (1L << e) * zeros;
        DP[e][0] = p + B[e][0];
        DP[e][1] = p + B[e][1];
    }

    ll f = 0, fmax = 0;
    for (int e = M-1; e >= 0; --e) {
        if ((K >> e) & 1) {
            fmax = max(fmax, f + DP[e][0]);
            f += B[e][1];
        } else {
            f += B[e][0];
        }
        fmax = max(fmax, f);
    }
    return fmax;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}