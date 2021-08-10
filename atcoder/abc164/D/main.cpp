#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(string const& S) {
    int const N = S.size();
    vector<ll> dp(2020, 0);
    dp[0] = 1;
    ll ans = 0;
    int v = 0;
    int e = 1;
    for (int i = N - 1; i >= 0; --i) {
        v = ((S[i] - '0') * e + v) % 2019;
        e = e * 10 % 2019;
        ans += dp[v];
        dp[v]++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    cout << solve(S) << endl;

    return 0;
}