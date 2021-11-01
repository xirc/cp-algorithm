#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int H, W;
vector<string> G;

int f(int y, int x) {
    int p = (y + x) % 2 ? 1 : -1;
    int delta =  G[y][x] == '+' ? +1 : -1;
    return p * delta;
}

string solve() {
    int const inf = 1e9;
    vector<vector<int>> DP(H, vector<int>(W, 0));
    DP[H-1][W-1] = 0;
    for (int y = H-1; y >= 0; --y) {
        for (int x = W-1; x >= 0; --x) {
            if (y == H-1 && x == W-1) continue;
            int p = (x + y) % 2;
            int b = y + 1 < H ? (DP[y+1][x] + f(y+1,x)) : (p ? inf : -inf);
            int r = x + 1 < W ? (DP[y][x+1] + f(y,x+1)) : (p ? inf : -inf);
            if (p) {
                DP[y][x] = min(b, r);
            } else {
                DP[y][x] = max(b, r);
            }
        }
    }
    if (DP[0][0] > 0) {
        return "Takahashi";
    } else if (DP[0][0] < 0) {
        return "Aoki";
    } else {
        return "Draw";
    }
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