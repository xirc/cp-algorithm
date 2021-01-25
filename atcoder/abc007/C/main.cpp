#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int W, H;
int sy, sx, gy, gx;
vector<string> G; 

int solve() {
    assert(G[sy][sx] == '.');
    assert(G[gy][gx] == '.');

    vector<int> dx = { 1, -1, 0, 0 };
    vector<int> dy = { 0, 0, 1, -1 };
    vector<vector<bool>> done(H, vector<bool>(W, false));
    queue<tuple<int, int, int>> Q;
    Q.push({ sy, sx, 0 });
    done[sy][sx] = true;
    while (Q.size()) {
        int y, x, ds;
        tie(y, x, ds) = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= H) continue;
            if (nx < 0 || nx >= W) continue;
            if (done[ny][nx]) continue;
            if (G[ny][nx] == '#') continue;
            if (ny == gy && nx == gx) {
                return ds + 1;
            }
            done[ny][nx] = true;
            Q.push({ ny, nx, ds + 1 });
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    cin >> sy >> sx >> gy >> gx;
    --sy, --sx, --gy, --gx;
    G.assign(H, "");
    for (int i = 0; i < H; ++i) {
        cin >> G[i];
    }
    cout << solve() << endl;

    return 0;
}