#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

string solve(int A, int B, ll K) {
    int const M = 61;
    vector<vector<ll>> DP(M, vector<ll>(M, 0));
    DP[0][0] = 0;
    for (int n = 1; n < M; ++n) {
        DP[n][0] = DP[n][n] = 1;
        for (int k = 1; k < n; ++k) {
            DP[n][k] = DP[n-1][k-1] + DP[n-1][k];
        }
    }

    vector<char> cs;
    while (K > 0) {
        ll ps = DP[A+B-1][A-1];
        if (ps > K) {
            cs.push_back('a');
            --A;
        } else {
            cs.push_back('b');
            --B;
            K -= ps;
        }
    }
    while (A > 0) {
        cs.push_back('a');
        --A;
    }
    while (B > 0) {
        cs.push_back('b');
        --B;
    }
    return string(cs.begin(), cs.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    ll K;

    cin >> A >> B >> K;
    --K;
    cout << solve(A, B, K) << endl;

    return 0;
}