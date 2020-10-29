#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll M = 1000000007;

bool is_valid_pattern(int p, int W) {
    for (int i = 0; i + 1 < W; ++i) {
        bool o1 = (p >> i) & 1;
        bool o2 = (p >> (i+1)) & 1;
        if (o1 && o2) return false;
    }
    return true;
}

vector<int> count_dx(int x, int W) {
    vector<int> ans(3, 0); // x-1, x, x+1
    const int L = 1 << (W-1);
    for (int p = 0; p < L; ++p) {
        if (!is_valid_pattern(p, W)) continue;
        // move left
        if (x - 1 >= 0 && (p >> (x - 1)) & 1) {
            ++ans[0];
        }
        // move down
        bool lb = x - 1 < 0 || ((p >> (x - 1)) & 1) == 0;
        bool rb = x + 1 >= W || ((p >> x) & 1) == 0;
        if (lb && rb) {
            ++ans[1];
        }
        // move right
        if (x + 1 < W && ((p >> x) & 1)) {
            ++ans[2];
        }
    }
    return ans;
}

ll solve(int H, int W, int K) {
    vector<vector<int>> P;
    P.assign(W, vector<int>());
    for (int x = 0; x < W; ++x) {
        P[x] = count_dx(x, W);
    }

    vector<vector<ll>> DP(H + 1, vector<ll>(W, 0));
    DP[0][0] = 1;
    for (int x = 1; x < W; ++x) {
        DP[0][x] = 0;
    }
    for (int y = 1; y <= H; ++y) {
        for (int x = 0; x < W; ++x) {
            DP[y][x-1] += DP[y-1][x] * P[x][0] % M;
            DP[y][x]   += DP[y-1][x] * P[x][1] % M;
            DP[y][x+1] += DP[y-1][x] * P[x][2] % M;
            DP[y][x-1] %= M;
            DP[y][x]   %= M;
            DP[y][x+1] %= M;
        }
    }
    return DP[H][K-1];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, W, K;
    cin >> H >> W >> K;
    cout << solve(H, W, K) << endl;

    return 0;
}