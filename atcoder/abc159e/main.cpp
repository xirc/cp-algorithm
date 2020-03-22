// https://atcoder.jp/contests/abc159/tasks/abc159_e

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int H, W, K;
vector<vector<int>> G;

vector<vector<int>> DP;
void dp() {
    DP.assign(H, vector<int>(W, 0));
    DP[0][0] = G[0][0];
    for (int x = 1; x < W; ++x) {
        DP[0][x] = DP[0][x-1] + G[0][x];
    }
    for (int y = 1; y < H; ++y) {
        DP[y][0] = DP[y-1][0] + G[y][0];
    }
    for (int y = 1; y < H; ++y) {
        for (int x = 1; x < W; ++x) {
            DP[y][x] = DP[y-1][x] + DP[y][x-1] - DP[y-1][x-1] + G[y][x];
        }
    }
}
// [xl,xr), [yl,yr)
int query(int xl, int xr, int yl, int yr) {
    if (yr - yl == 0 || xr - xl == 0) return 0;
    int ans =  DP[yr-1][xr-1];
    if (yl > 0) {
        ans -= DP[yl-1][xr-1];
    }
    if (xl > 0) {
        ans -= DP[yr-1][xl-1];
    }
    if (yl > 0 && xl > 0) {
        ans += DP[yl-1][xl-1];
    }
    return ans;
}

const int inf = 1e8;
int divx(vector<pair<int,int>>& ys) {
    int ans = 0;
    int xl = 0;
    for (int xr = 1; xr <= W;) {
        bool succ = true;
        for (int i = 0; i < ys.size(); ++i) {
            int yl = ys[i].first, yr = ys[i].second;
            int d = query(xl, xr, yl, yr);
            succ &= d <= K;
        }
        if (succ) {
            xr++;
            continue;
        }
        if (xr - xl <= 1) {
            return inf;
        }
        ans++;
        xl = xr-1;
    }
    return ys.size() - 1 + ans;
}

int divy() {
    int ans = inf;
    for (int b = 0; b < (1 << H); b++) {
        vector<pair<int,int>> ys;
        int l = 0;
        for (int r = 0; r < H; ++r) {
            if (b & (1 << r)) {
                ys.push_back({l,r+1});
                l = r+1;
            }
        }
        if (l < H) {
            ys.push_back({l,H});
        }
        ans = min(ans, divx(ys));
    }
    return ans;
}

int solve() {
    dp();
    return divy();
}

int main() {
    cin >> H >> W >> K;
    G.assign(H, vector<int>(W, 0));
    for (int y = 0; y < H; ++y) {
        string line;
        cin >> line;
        for (int x = 0; x < W; ++x) {
            G[y][x] = line[x] - '0';
        }
    }
    cout << solve() << endl;
    return 0;
}