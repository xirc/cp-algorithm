#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> A;

int solve() {
    vector<vector<int>> DP(2, vector<int>(N, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < N; ++j) {
            DP[i][j] = max(DP[i][j], A[i][j]);
            if (i > 0) {
                DP[i][j] = max(DP[i][j], DP[i-1][j] + A[i][j]);
            }
            if (j > 0) {
                DP[i][j] = max(DP[i][j], DP[i][j-1] + A[i][j]);
            }
        }
    }
    return DP[1][N-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(2, vector<int>(N, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    cout << solve() << endl;

    return 0;
}