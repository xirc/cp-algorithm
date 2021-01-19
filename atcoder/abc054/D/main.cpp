#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, MA, MB;
vector<int> as, bs, cs;

int solve() {
    const int inf = 1e8;
    const int K = 500;
    vector<vector<int>> dp(K, vector<int>(K, inf));
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        auto ndp = dp;
        int a = as[i], b = bs[i], c = cs[i];
        for (int ta = 0; ta < K; ++ta) {
            for (int tb = 0; tb < K; ++tb) {
                int tc = dp[ta][tb];
                int na = a + ta, nb = b + tb, nc = tc + c;
                if (na >= K || nb >= K) continue;
                ndp[na][nb] = min(ndp[na][nb], nc);
            }
        }
        dp = ndp;
    }
    int ans = inf;
    for (int a = 0; a < K; ++a) {
        for (int b = 0; b < K; ++b) {
            if (a == 0 && b == 0) continue;
            if (a * MB != b * MA) continue;
            ans = min(ans, dp[a][b]);
        }
    }
    return ans == inf ? -1 : ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> MA >> MB;
    as.assign(N, 0);
    bs.assign(N, 0);
    cs.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> as[i] >> bs[i] >> cs[i];
    }
    cout << solve() << endl;

    return 0;
}