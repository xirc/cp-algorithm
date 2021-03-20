#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, K;
vector<vector<int>> A;

int solve() {
    int const M = K * 2;
    vector<vector<int>> DP(2 * M, vector<int>(2 * M));
    for (int y = 0; y < M; ++y) {
        for (int x = 0; x < M; ++x) {
            DP[y+K][x+K] += A[y][x];
            DP[y+M][x+K] -= A[y][x];
            DP[y+K][x+M] -= A[y][x];
            DP[y+M][x+M] += A[y][x];
        }
    }
    for (int y = 0; y < 2*M; ++y) {
        for (int x = 1; x < 2*M; ++x) {
            DP[y][x] += DP[y][x-1];
        }
    }
    for (int x = 0; x < 2*M; ++x) {
        for (int y = 1; y < 2*M; ++y) {
            DP[y][x] += DP[y-1][x];
        }
    }

    int ans = 0;
    for (int y = K; y < K + M; ++y) {
        for (int x = K; x < K + M; ++x) {
            int c = 0;
            for (int i = -4; i <= 4; ++i) {
                int cy = y + i * K;
                if (cy < 0 || cy >= 2 * M) continue;
                for (int j = -4; j <= 4; ++j) {
                    int cx = x + j * K;
                    if (cx < 0 || cx >= 2 * M) continue;
                    if ((i + j) % 2 == 0) {
                        c += DP[cy][cx];
                    }
                }
            }
            ans = max(ans, c);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(2 * K, vector<int>(2 * K));
    for (int i = 0; i < N; ++i) {
        int x, y;
        string c;
        cin >> x >> y >> c;
        x %= 2*K;
        y %= 2*K;
        if (c == "B") {
            A[y][x] += 1;
        } else if (c == "W") {
            A[y][(x+K)%(2*K)] += 1;
        } else throw;
    }
    cout << solve() << endl;

    return 0;
}