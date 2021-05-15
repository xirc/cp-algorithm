#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, K;
vector<int> A;

int solve() {
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        vector<bool> dp(K, false);
        dp[0] = true;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            for (int k = K - 1 - A[j]; k >= 0; --k) {
                dp[k + A[j]] = dp[k + A[j]] || dp[k];
            }
        }
        bool required = false;
        for (int k = K - 1; k >= 0; --k) {
            if (dp[k] && k + A[i] >= K) {
                required = true;
                break;
            }
        }
        if (!required) ++ans;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    cout << solve() << endl;

    return 0;
}