#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int H, W;
int sy, sx;
int ex, ey;
vector<string> G;

int solve() {
    using P = array<int,3>;
    int const inf = 1e8;
    vector<int> const dx = { 1, -1, 0, 0 };
    vector<int> const dy = { 0, 0, 1, -1 };

    priority_queue<P, vector<P>, greater<P>> Q;
    vector<vector<bool>> F(H, vector<bool>(W, false));
    vector<vector<int>> D(H, vector<int>(W, inf));
    D[sy][sx] = 0;
    Q.push({ 0, sy, sx });
    while (Q.size()) {
        auto p = Q.top(); Q.pop();
        int y = p[1], x = p[2];
        if (y == ey && x == ex) return D[y][x];
        if (F[y][x]) continue;
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= H) continue;
            if (nx < 0 || nx >= W) continue;
            if (G[ny][nx] == '#') continue;
            if (D[ny][nx] > D[y][x]) {
                D[ny][nx] = D[y][x];
                Q.push({ D[y][x], ny, nx });
            }
        }
        for (int dy = -2; dy <= 2; ++dy) {
            for (int dx = -2; dx <= 2; ++dx) {
                int ny = y + dy, nx = x + dx;
                if (ny < 0 || ny >= H) continue;
                if (nx < 0 || nx >= W) continue;
                if (G[ny][nx] == '#') continue;
                if (D[ny][nx] > D[y][x] + 1) {
                    D[ny][nx] = D[y][x] + 1;
                    Q.push({ D[y][x] + 1, ny, nx });
                }
            }
        }
        F[y][x] = true;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    cin >> sy >> sx;
    cin >> ey >> ex;
    --sy, --sx, --ey, --ex;
    G.assign(H, "");
    for (int y = 0; y < H; ++y) {
        cin >> G[y];
    }
    cout << solve() << endl;

    return 0;
}