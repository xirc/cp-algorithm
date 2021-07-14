#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int const inf = 1e6;
int H, W;
vector<string> G;

vector<int> const dx = { 1, -1, 0, 0 };
vector<int> const dy = { 0, 0, 1, -1 };
vector<vector<int>> solve(int sy, int sx) {
    vector<vector<int>> D(H, vector<int>(W, inf));
    queue<array<int,2>> Q;
    Q.push({ sy, sx });
    D[sy][sx] = 0;
    while (Q.size()) {
        auto p = Q.front(); Q.pop();
        int y = p[0], x = p[1];
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= H) continue;
            if (nx < 0 || nx >= W) continue;
            if (G[ny][nx] == '#') continue;
            if (D[ny][nx] <= D[y][x] + 1) continue;
            D[ny][nx] = D[y][x] + 1;
            Q.push({ ny, nx });
        }
    }
    return D;
}

int maximum(vector<vector<int>> const& D) {
    int ans = 0;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (D[y][x] == inf) continue;
            ans = max(ans, D[y][x]);
        }
    }
    return ans;
}

int solve() {
    int ans = 0;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (G[y][x] == '#') continue;
            auto d = solve(y, x);
            ans = max(ans, maximum(d));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    G.assign(H, "");
    for (int y = 0; y < H; ++y) {
        cin >> G[y];
    }
    cout << solve() << endl;

    return 0;
}