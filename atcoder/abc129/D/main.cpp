#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int H, W;
vector<string> S;

int solve() {
    using vi = vector<int>;
    using vii = vector<vi>;
    vii Dl, Dr, Dt, Db;
    Dl = Dr = Dt = Db = vii(H, vi(W, 0));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (S[y][x] == '#') continue;
            int p = x - 1 >= 0 ? Dr[y][x-1] : 0;
            Dr[y][x] = p + 1;
        }
        for (int x = W - 1; x >= 0; --x) {
            if (S[y][x] == '#') continue;
            int p = x + 1 < W ? Dl[y][x+1] : 0;
            Dl[y][x] = p + 1;
        }
    }
    for (int x = 0; x < W; ++x) {
        for (int y = 0; y < H; ++y) {
            if (S[y][x] == '#') continue;
            int p = y - 1 >= 0 ? Db[y-1][x] : 0;
            Db[y][x] = p + 1;
        }
        for (int y = H - 1; y >= 0; --y) {
            if (S[y][x] == '#') continue;
            int p = y + 1 < H ? Dt[y+1][x] : 0;
            Dt[y][x] = p + 1;
        }
    }

    int ans = 0;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            int lighten = Dl[y][x] + Dr[y][x] + Db[y][x] + Dt[y][x] - 3;
            ans = max(ans, lighten);
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