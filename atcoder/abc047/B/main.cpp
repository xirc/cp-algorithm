#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int W, H, N;
    cin >> W >> H >> N;

    vector<vector<bool>> G(H, vector<bool>(W, true));
    for (int i = 0; i < N; i++) {
        int xi, yi, ai;
        cin >> xi >> yi >> ai;
        if (ai == 1) {
            for (int y = 0; y < H; ++y) {
                for (int x = 0; x < xi; ++x) {
                    G[y][x] = false;
                }
            }
        } else if (ai == 2) {
            for (int y = 0; y < H; ++y) {
                for (int x = xi; x < W; ++x) {
                    G[y][x] = false;
                }
            }
        } else if (ai == 3) {
            for (int y = 0; y < yi; ++y) {
                for (int x = 0; x < W; ++x) {
                    G[y][x] = false;
                }
            }
        } else if (ai == 4) {
            for (int y = yi; y < H; ++y) {
                for (int x = 0; x < W; ++x) {
                    G[y][x] = false;
                }
            }
        }
    }

    int area = 0;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            area += G[y][x] ? 1 : 0;
        }
    }
    cout << area << endl;

    return 0;
}