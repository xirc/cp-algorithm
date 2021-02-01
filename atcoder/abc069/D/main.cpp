#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int H, W, N;
vector<int> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int i = 0;
    vector<vector<int>> G(H, vector<int>(W, 0));
    for (int y = 0; y < H; ++y) {
        for (int j = 0; j < W; ++j) {
            int x = y % 2 ? (W - 1 - j) : j;
            while (A[i] == 0) ++i;
            G[y][x] = i + 1;
            --A[i];
        }
    }
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (x > 0) cout << " ";
            cout << G[y][x];
        }
        cout << endl;
    }

    return 0;
}