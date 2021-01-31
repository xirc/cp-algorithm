#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int H, W;
vector<string> G;

int solve() {
    int wc = 0;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (G[y][x] == '.') ++wc;
        }
    }

    vector<int> dx = { 1, -1, 0, 0 };
    vector<int> dy = { 0, 0, 1, -1 };
    vector<vector<bool>> done(H, vector<bool>(W, false));
    queue<vector<int>> Q;
    Q.push({ 0, 0, 1 });
    done[0][0] = true;
    while (Q.size()) {
        auto e = Q.front(); Q.pop();
        int y = e[0], x = e[1], c = e[2];
        if (y == H - 1 && x == W - 1) {
            return wc - c;
        }
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= H) continue;
            if (nx < 0 || nx >= W) continue;
            if (G[ny][nx] == '#') continue;
            if (done[ny][nx]) continue;
            done[ny][nx] = true;
            Q.push({ ny, nx, c + 1 });
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    G.assign(H, "");
    for (int i = 0; i < H; ++i) {
        cin >> G[i];
    }
    cout << solve() << endl;

    return 0;
}