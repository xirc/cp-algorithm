#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int H, W, K;
vector<vector<int>> G;

ll solve() {
    int const K = 4;
    vector<vector<vector<ll>>> DP(H, vector<vector<ll>>(W, vector<ll>(K, 0)));
    ll ans = 0;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            for (int i = 0; i < K; ++i) {
                ll vl = x > 0 ? DP[y][x-1][i] : 0;
                DP[y][x][i] = max(DP[y][x][i], vl);
            }
            for (int i = 1; i < K; ++i) {
                ll vl = x > 0 ? DP[y][x-1][i-1] : 0;
                DP[y][x][i] = max(DP[y][x][i], vl + G[y][x]);
            }
            for (int i = 0; i < K; ++i) {
                ll vu = y > 0 ? DP[y-1][x][i] : 0;
                DP[y][x][0] = max(DP[y][x][0], vu);
                DP[y][x][1] = max(DP[y][x][1], vu + G[y][x]);
            }
            for (int i = 0; i < K; ++i) {
                ans = max(ans, DP[y][x][i]);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W >> K;
    G.assign(H, vector<int>(W, 0));
    for (int i = 0; i < K; ++i) {
        int r, c, v;
        cin >> r >> c >> v;
        --r, --c;
        G[r][c] = v;
    }
    cout << solve() << endl;

    return 0;
}