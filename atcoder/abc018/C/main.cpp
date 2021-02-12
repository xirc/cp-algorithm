#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int R, C, K;
vector<string> G;

int solve() {
    vector<vector<int>> M(R, vector<int>(C, 0));

    priority_queue<vector<int>> Q;
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            if (G[y][x] == 'x') {
                Q.push({ K, x, y });
            }
        }
    }
    
    vector<int> dx = { 1, -1, 0, 0 };
    vector<int> dy = { 0, 0, 1, -1 };
    while (Q.size()) {
        auto e = Q.top(); Q.pop();
        auto k = e[0], x = e[1], y  = e[2];
        assert(k >= 1);
        if (M[y][x] >= k) continue;
        M[y][x] = k;
        if (k == 1) continue;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i], nk = k - 1;
            if (nx < 0 || nx >= C) continue;
            if (ny < 0 || ny >= R) continue;
            if (M[ny][nx] >= nk) continue;
            Q.push({ nk, nx, ny });
        }
    }

    int ans = 0;
    for (int y = K - 1; y < R - K + 1; ++y) {
        for (int x = K - 1; x < C - K + 1; ++x) {
            if (M[y][x] == 0) ++ans;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> R >> C >> K;
    G.assign(R, "");
    for (int i = 0; i < R; ++i) {
        cin >>G[i];
    }
    cout << solve() << endl;

    return 0;
}