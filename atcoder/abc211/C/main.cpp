#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    int const n = s.size();
    string const t = "chokudai";
    ll const MOD = 1e9+7;

    vector<ll> dp(9, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (s[i] == t[j]) {
                dp[j+1] += dp[j];
                dp[j+1] %= MOD;
            }
        }
    }
    cout << dp[8] << endl;

    return 0;
}