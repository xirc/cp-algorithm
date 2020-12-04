#include <bits/stdc++.h>

using namespace std;

int H, W;
vector<string> S;

bool solve() {
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (S[y][x] == '.') continue;
            int cnt = 0;
            if (y - 1 >= 0) cnt += S[y-1][x] == '#' ? 1 : 0;
            if (y + 1 < H) cnt += S[y+1][x] == '#' ? 1 : 0;
            if (x - 1 >= 0) cnt += S[y][x-1] == '#' ? 1 : 0;
            if (x + 1 < W) cnt += S[y][x+1] == '#' ? 1 : 0;
            if (cnt == 0) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    S.assign(H, "");
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }
    auto ans = solve() ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}