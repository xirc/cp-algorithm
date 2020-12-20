#include <bits/stdc++.h>

using namespace std;

int H, W;
vector<vector<int>> C(10, vector<int>(10));
vector<vector<int>> A;

int solve() {
    // Floyd-Warshall
    for (int k = 0; k < 10; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] == -1) continue;
            ans += C[A[i][j]][1];
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    A.assign(H, vector<int>(W, 0));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> C[i][j];
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    cout << solve() << endl;

    return 0;
}