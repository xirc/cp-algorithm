#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll MOD = 1000000007;

int N;
vector<string> S(2);

ll solve() {
    vector<ll> DP(N, 0);
    for (int x = 0; x < N; ++x) {
        if (S[0][x] == S[1][x]) {
            if (x == 0) {
                // |
                DP[x] = 3;
            } else if (S[0][x-1] == S[1][x-1]) {
                // ||
                DP[x] = DP[x-1] * 2 % MOD;
            } else {
                // =|
                DP[x] = DP[x-1];
            }
        } else if (x > 0 && S[0][x] == S[0][x-1]) {
            // =
            DP[x] = DP[x-1];
        } else {
            if (x == 0) {
                // =
                DP[x] = 6;
            } else if (S[0][x-1] == S[1][x-1]) {
                // |=
                DP[x] = DP[x-1] * 2 % MOD;
            } else {
                // ==
                DP[x] = DP[x-1] * 3 % MOD;
            }
        }
    }
    return DP[N-1];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> S[0] >> S[1];
    cout << solve() << endl;

    return 0;
}