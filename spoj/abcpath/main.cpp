// https://www.spoj.com/problems/ABCPATH/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int H, W;
vector<vector<char>> G;

vector<vector<int>> cache_count;

int dfs(int x, int y, int count) {
    static int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    static int dy[] = { 1, 1, 1, 0, -1, -1, -1, 0 };

    if (cache_count[y][x] >= 0) {
        return count + cache_count[y][x];
    }

    int ans = count;
    char c = G[y][x];
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
        char nc = G[ny][nx];
        if (nc - c != 1) continue;
        auto na = dfs(nx, ny, count + 1);
        ans = max(ans, na);
    }
    cache_count[y][x] = ans - count;
    return ans;
}

int solve() {
    int ans = 0;
    cache_count.assign(H, vector<int>(W, -1));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (G[y][x] != 'A') continue;
            auto na = dfs(x, y, 1);
            ans = max(ans, na);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int id = 1;
    while (true) {
        cin >> H >> W;
        if (H == 0 || W == 0) break;
        G.assign(H, vector<char>(W));
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                cin >> G[y][x];
            }
        }
        auto ans = solve();
        cout << "Case " << id << ": " << ans << endl;
        id++;
    }

    return 0;
}