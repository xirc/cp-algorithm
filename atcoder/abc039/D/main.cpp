#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int H, W;
vector<string> G;
vector<string> D;

bool solve() {
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (G[y][x] != '#') continue;
            bool all_ones = true;
            for (int dx = -1; dx <= 1; ++dx) {
                int nx = x + dx;
                if (nx < 0 || nx >= W) continue;
                for (int dy = -1; dy <= 1; ++dy) {
                    int ny = y + dy;
                    if (ny < 0 || ny >= H) continue;
                    if (G[ny][nx] != '#') {
                        all_ones = false;
                        break;
                    }
                }
            }
            if (all_ones) {
                D[y][x] = '#';
            }
        }
    }
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (G[y][x] != '#') continue;
            bool any_one = false;
            for (int dx = -1; dx <= 1; ++dx) {
                int nx = x + dx;
                if (nx < 0 || nx >= W) continue;
                for (int dy = -1; dy <= 1; ++dy) {
                    int ny = y + dy;
                    if (ny < 0 || ny >= H) continue;
                    if (D[ny][nx] == '#') {
                        any_one = true;
                        break;
                    }
                }
            }
            if (!any_one) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    G.assign(H, "");
    D.assign(H, string(W, '.'));
    for (int i = 0; i < H; ++i) {
        cin >> G[i];
    }
    auto possible = solve();
    if (possible) {
        cout << "possible" << endl;
        for (int i = 0; i < H; ++i) {
            cout << D[i] << endl;
        }
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}