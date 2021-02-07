#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int H, W;
vector<string> S;

int solve() {
    vector<vector<int>> G(H, vector<int>(W, 0));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            G[y][x] = S[y][x] == '#' ? 1 : 0;
        }
    }
    for (int y = 0; y < H; ++y) {
        for (int x = W-1; x > 0 ; --x) {
            G[y][x] -= G[y][x-1];
        }
    }
    for (int x = 0; x < W; ++x) {
        for (int y = H-1; y > 0; --y) {
            G[y][x] -= G[y-1][x];
        }
    }
    int ans = 0;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (G[y][x] != 0) ++ans;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    S.assign(H, "");
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }
    cout << solve() << endl;

    return 0;
}