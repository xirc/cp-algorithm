#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using lf = long double;

int N;
ll X, Y, D;

lf solve() {
    if (X % D != 0 || Y % D != 0) return 0;
    X /= D;
    Y /= D;
    if (X > N || Y > N) return 0;

    vector<vector<lf>> C(N+1, vector<lf>(N+1, 0));
    C[0][0] = 1.0;
    for (int n = 1; n <= N; ++n) {
        C[n][0] = powl(0.5, n);
        for (int k = 1; k <= n; ++k) {
            C[n][k] = (C[n-1][k-1] + C[n-1][k]) / 2;
        }
    }

    int M = 2 * N + 1;
    vector<vector<lf>> DP(N+1, vector<lf>(M, 0));
    DP[0][0+N] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j - 1 >= 0) {
                DP[i][j-1] += DP[i-1][j] / 2;
            }
            if (j + 1 < M) {
                DP[i][j+1] += DP[i-1][j] / 2;
            }
        }
    }

    vector<lf> ps;
    for (int i = 0; i <= N; ++i) {
        auto px = DP[i][X + N];
        auto py = DP[N-i][Y + N];
        ps.push_back(C[N][i] * px * py);
    }
    sort(ps.begin(), ps.end());
    return accumulate(ps.begin(), ps.end(), lf(0), plus<lf>());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> D;
    cin >> X >> Y;
    cout << fixed << setprecision(9) << solve() << endl;

    return 0;
}