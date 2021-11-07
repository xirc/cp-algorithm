#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int H, W, A, B;
vector<vector<bool>> G;

int dfs(int n) {
    if (n == H * W) return 1;
    int y = n / W, x = n % W;
    if (G[y][x]) {
        return dfs(n+1);
    }
    int ans = 0;
    // 1x1
    if (B > 0) {
        G[y][x] = true;
        --B;
        ans += dfs(n+1);
        G[y][x] = false;
        ++B;
    }
    // 2x1
    if (A > 0 && y+1 < H && !G[y+1][x]) {
        G[y][x] = true;
        G[y+1][x] = true;
        --A;
        ans += dfs(n+1);
        G[y][x] = false;
        G[y+1][x] = false;
        ++A;
    }
    // 1x2
    if (A > 0 && x+1 < W && !G[y][x+1]) {
        G[y][x] = true;
        G[y][x+1] = true;
        --A;
        ans += dfs(n+1);
        G[y][x] = false;
        G[y][x+1] = false;
        ++A;
    }
    return ans;
}

int solve() {
    G = vector<vector<bool>>(H, vector<bool>(W, false));
    return dfs(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W >> A >> B;
    cout << solve() << endl;

    return 0;
}