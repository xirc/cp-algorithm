#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A, B;

// O (N M K)
// O (200 x 200 x 512)
int solve() {
    const int K = 1 << 10;
    vector<vector<bool>> DP(N, vector<bool>(K, false));
    for (int j = 0; j < M; ++j) {
        int ci = A[0] & B[j];
        DP[0][ci] = true;
    }
    for (int i = 1; i < N; ++i) {
        for (int ci = 0; ci < K; ++ci) {
            if (!DP[i-1][ci]) continue;
            for (int j = 0; j < M; ++j) {
                int cci = ci | (A[i] & B[j]);
                DP[i][cci] = true;
            }
        }
    }
    for (int ci = 0; ci < K; ++ci) {
        if (DP[N-1][ci]) return ci;
    }
    return K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(N, 0);
    B.assign(M, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    cout << solve() << endl;

    return 0;
}