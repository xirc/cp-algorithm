#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

vector<vector<int>> reverseW(vector<vector<int>> const& A) {
    int const H = A.size(), W = A[0].size();
    vector<vector<int>> B(H, vector<int>(W, 0));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            B[y][W-1-x] = A[y][x];
        }
    }
    return B;
}

ll solve(vector<vector<int>> const& A, int C) {
    int const H = A.size(), W = A[0].size();
    ll const inf = 1e18;
    ll ans = inf;
    vector<vector<ll>> DP(H, vector<ll>(W, inf));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (y > 0) {
                DP[y][x] = min({
                    DP[y][x],
                    DP[y-1][x] - A[y-1][x] + A[y][x] + C,
                    ll(0) + A[y][x] + A[y-1][x] + C
                });
            }
            if (x > 0) {
                DP[y][x] = min({
                    DP[y][x],
                    DP[y][x-1] - A[y][x-1] + A[y][x] + C,
                    ll(0) + A[y][x] + A[y][x-1] + C
                });
            }
            ans = min(ans, DP[y][x]);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, W, C;
    vector<vector<int>> A;
    cin >> H >> W >> C;
    A.assign(H, vector<int>(W, 0));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cin >> A[y][x];
        }
    }
    auto ans1 = solve(A, C);
    A = reverseW(A);
    auto ans2 = solve(A, C);
    cout << min(ans1, ans2) << endl;

    return 0;
}