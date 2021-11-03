#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int H, W;
vector<string> G;

int solve() {
    int sy, sx, gy, gx;
    vector<vector<int>> teleporters(26);
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            auto cell = G[y][x];
            if (cell == 'S') {
                sy = y; sx = x;
            } else if (cell == 'G') {
                gy = y; gx = x;
            } else if (cell >= 'a' && cell <= 'z') {
                auto id = cell - 'a';
                teleporters[id].push_back(y);
                teleporters[id].push_back(x);
            }
        }
    }

    int const inf = 1e8;
    vector<int> const dx = { 1, -1, 0, 0 };
    vector<int> const dy = { 0, 0, 1, -1 };
    vector<bool> is_teleporter_used(26, false);
    vector<vector<int>> D(H, vector<int>(W, inf));
    queue<array<int,2>> Q;
    D[sy][sx] = 0;
    Q.push({ sy, sx });
    while (Q.size()) {
        auto y = Q.front()[0];
        auto x = Q.front()[1];
        Q.pop();
        if (y == gy && x == gx) {
            return D[y][x];
        }
        for (int i = 0; i < 4; ++i) {
            auto ny = y + dy[i];
            auto nx = x + dx[i];
            if (ny < 0 || ny >= H) continue;
            if (nx < 0 || nx >= W) continue;
            if (G[ny][nx] == '#') continue;
            if (D[y][x] + 1 >= D[ny][nx]) continue;
            D[ny][nx] = D[y][x] + 1;
            Q.push({ ny, nx });
        }
        if (G[y][x] >= 'a' && G[y][x] <= 'z') {
            auto id = G[y][x] - 'a';
            if (!is_teleporter_used[id]) {
                is_teleporter_used[id] = true;
                for (int i = 0; i < teleporters[id].size(); i += 2) {
                    int ny = teleporters[id][i];
                    int nx = teleporters[id][i+1];
                    if (D[y][x] + 1 < D[ny][nx]) {
                        D[ny][nx] = D[y][x] + 1;
                        Q.push({ ny, nx });
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    G.assign(H, "");
    for (auto &row : G) {
        cin >> row;
    }
    cout << solve() << endl;

    return 0;
}