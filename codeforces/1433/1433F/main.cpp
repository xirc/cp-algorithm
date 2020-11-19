#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<vector<int>> A;

// O (N M K L)
int solve() {
    int L = M / 2 + 1;
    vector<vector<vector<int>>> DP(N, vector<vector<int>>(K, vector<int>(L, 0)));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i > 0) {
                for (int s = 0; s < K; ++s) {
                    DP[i][s][0] = *max_element(DP[i-1][s].begin(), DP[i-1][s].end());
                }
            }
            for (int ll = L - 1; ll > 0; --ll) {
                for (int s = 0; s < K; ++s) {
                    int ns = (s + A[i][j]) % K;
                    if (s == 0 || DP[i][s][ll-1] > 0) {
                        DP[i][ns][ll] = max(DP[i][ns][ll], A[i][j] + DP[i][s][ll-1]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int ll = 0; ll < L; ++ll) {
        ans = max(ans, DP[N-1][0][ll]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    A.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    cout << solve() << endl;

    return 0;
}