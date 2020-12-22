#include <bits/stdc++.h>

using namespace std;

int H, W;
vector<string> S;

void solve() {
    vector<int> ds = { -1, 0, 1 };
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (S[y][x] == '#') continue;
            int count = 0;
            for (int dx : ds) {
                int nx = x + dx;
                if (nx < 0 || nx >= W) continue;
                for (int dy : ds) {
                    int ny = y + dy;
                    if (ny < 0 || ny >= H) continue;
                    if (S[ny][nx] == '#') ++count;
                }
            }
            S[y][x] = '0' + count;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    S.assign(H, "");
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    solve();

    for (int i = 0; i < H; ++i) {
        cout << S[i] << endl;
    }

    return 0;
}