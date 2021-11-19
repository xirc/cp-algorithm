#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int H, W;
vector<string> G;

int solve() {
    using entry = array<int,2>;
    int const inf = 1e8;
    vector<vector<int>> D(H, vector<int>(W, inf));
    deque<entry> Q;
    vector<int> const dy = { 1, -1, 0, 0 };
    vector<int> const dx = { 0, 0, 1, -1 };

    D[0][0] = 0;
    Q.push_back({ 0, 0 });
    while (Q.size()) {
        auto e = Q.front(); Q.pop_front();
        int y = e[0], x = e[1];
        if (y == H-1 && x == W-1) return D[y][x];
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= H) continue;
            if (nx < 0 || nx >= W) continue;
            if (G[ny][nx] == '.' && D[ny][nx] > D[y][x]) {
                D[ny][nx] = D[y][x];
                Q.push_front({ ny, nx });
            }
        }
        for (int dy = -2; dy <= 2; ++dy) {
            int ny = y + dy;
            if (ny < 0 || ny >= H) continue;
            for (int dx = -2; dx <= 2; ++dx) {
                int nx = x + dx;
                if (nx < 0 || nx >= W) continue;
                if (abs(dy) + abs(dx) >= 4) continue;
                if (D[ny][nx] > D[y][x] + 1) {
                    D[ny][nx] = D[y][x] + 1;
                    Q.push_back({ ny, nx });
                }
            }
        }
    }
    return D[H-1][W-1];
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