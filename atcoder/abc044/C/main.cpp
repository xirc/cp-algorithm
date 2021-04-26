#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, A;
vector<int> xs;

ll solve() {
    const int M = 50 * 50;
    vector<vector<ll>> DP(N+1, vector<ll>(M+1, 0));
    DP[0][0] = 1;

    for (auto x : xs) {
        for (int i = N; i > 0; --i) {
            for (int j = M; j - x >= 0; --j) {
                DP[i][j] += DP[i-1][j-x];
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += DP[i][i*A];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> A;
    xs.assign(N, 0);
    for (auto &x : xs) cin >> x;
    cout << solve() << endl;

    return 0;
}