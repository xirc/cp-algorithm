#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int H, W;
vector<vector<int>> A;

vector<vector<int>> solve() {
    vector<int> row_sum(H, 0), col_sum(W, 0);
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            row_sum[y] += A[y][x];
            col_sum[x] += A[y][x];
        }
    }
    vector<vector<int>> B(H, vector<int>(W, 0));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            B[y][x] = row_sum[y] + col_sum[x] - A[y][x];
        }
    }
    return B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    A.assign(H, vector<int>(W));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cin >> A[y][x];
        }
    }

    auto B = solve();
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (x > 0) cout << " ";
            cout << B[y][x];
        }
        cout << endl;
    }

    return 0;
}