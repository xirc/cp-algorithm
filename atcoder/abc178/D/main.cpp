#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(int S) {
    int const MOD = 1e9+7;
    vector<int> DP(2001, 0);
    DP[0] = 1; DP[1] = DP[2] = 0;
    for (int i = 3; i <= S; ++i) {
        DP[i] = (DP[i-1] + DP[i-3]) % MOD;
    }
    return DP[S];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int S;
    cin >> S;
    cout << solve(S) << endl;

    return 0;
}