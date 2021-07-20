#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;

    int const inf = 1e8;
    reverse(S.begin(), S.end());
    int const N = S.size();
    vector<vector<int>> DP(N + 1, vector<int>(2, inf));
    DP[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            int c = S[i] - '0' + j;
            if (c < 10) DP[i+1][0] = min(DP[i+1][0], DP[i][j] + c);
            DP[i+1][1] = min(DP[i+1][1], DP[i][j] + 10 - c);
        }
    }
    int ans = min(DP[N][0], DP[N][1] + 1);
    cout << ans << endl;

    return 0;
}