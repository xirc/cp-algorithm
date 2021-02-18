#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

ll const MOD = 1e9 + 7;
int H, W;
vector<vector<int>> A;
vector<vector<ll>> DP;

vector<int> dy = { 1, -1, 0, 0 };
vector<int> dx = { 0, 0, 1, -1};
ll dfs(int y, int x) {
    if (DP[y][x] >= 0) {
        return DP[y][x];
    }
    DP[y][x] = 1;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= H) continue;
        if (nx < 0 || nx >= W) continue;
        if (A[ny][nx] < A[y][x]) {
            DP[y][x] += dfs(ny, nx);
            DP[y][x] %= MOD;
        }
    }
    return DP[y][x];
}

ll solve() {
    DP.assign(H, vector<ll>(W, -1));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            dfs(y, x);
        }
    }
    ll ans = 0;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            assert(DP[y][x] >= 0);
            ans += DP[y][x];
            ans %= MOD;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    A.assign(H, vector<int>(W));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cin >> A[y][x];
        }
    }
    cout << solve() << endl;

    return 0;
}