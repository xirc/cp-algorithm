#include <bits/stdc++.h>

using namespace std;

// O(N)
int solve(vector<int> const& A) {
    const int inf = 2 * 1e5 * 2;
    const int N = A.size();
    if (N <= 1) {
        return A[0];
    }
    vector<vector<int>> DP(N, vector<int>(2, inf));
    DP[0][0] = A[0];
    DP[0][1] = inf;
    DP[1][0] = DP[0][0] + A[1];
    DP[1][1] = A[0];
    for (int i = 2; i < N; ++i) {
        DP[i][0] = min(DP[i-1][1] + A[i], DP[i-2][1] + A[i] + A[i-1]);
        DP[i][1] = min(DP[i-1][0], DP[i-2][0]);
    }
    return min(DP[N-1][0], DP[N-1][1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    vector<int> A;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << solve(A) << endl;
    }

    return 0;
}