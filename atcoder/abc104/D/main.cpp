#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll MOD = 1e9+7;

ll solve(string const& S) {
    const int N = S.size();

    vector<vector<ll>> DP(N, vector<ll>(4, 0));
    DP[0][0] = S[0] == '?' ? 3 : 1;
    DP[0][1] = (S[0] == 'A' || S[0] == '?') ? 1 : 0;
    DP[0][2] = DP[0][3] = 0;
    for (int i = 1; i < N; ++i) {
        auto ch = S[i];
        if (ch == '?') {
            DP[i][3] = (DP[i-1][3] * 3 + DP[i-1][2]) % MOD;
            DP[i][2] = (DP[i-1][2] * 3 + DP[i-1][1]) % MOD;
            DP[i][1] = (DP[i-1][1] * 3 + DP[i-1][0]) % MOD;
            DP[i][0] = (DP[i-1][0] * 3) % MOD;
        } else if (ch == 'A') {
            DP[i][3] = DP[i-1][3];
            DP[i][2] = DP[i-1][2];
            DP[i][1] = (DP[i-1][1] + DP[i-1][0]) % MOD;
            DP[i][0] = DP[i-1][0];
        } else if (ch == 'B') {
            DP[i][3] = DP[i-1][3];
            DP[i][2] = (DP[i-1][2] + DP[i-1][1]) % MOD;
            DP[i][1] = DP[i-1][1];
            DP[i][0] = DP[i-1][0];
        } else if (ch == 'C') {
            DP[i][3] = (DP[i-1][3] + DP[i-1][2]) % MOD;
            DP[i][2] = DP[i-1][2];
            DP[i][1] = DP[i-1][1];
            DP[i][0] = DP[i-1][0];
        } else throw;
    }
    return DP[N-1][3] % MOD;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    cout << solve(S) << endl;

    return 0;
}