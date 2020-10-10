#include <bits/stdc++.h>

using namespace std;

int solve(int H, int W, vector<string> S) {
    int ans = 0;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (S[y][x] == '#') continue;
            if (x + 1 < W && S[y][x+1] == '.') {
                ++ans;
            }
            if (y + 1 < H && S[y+1][x] == '.') {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, W;
    vector<string> S;

    cin >> H >> W;
    S.assign(H, "");
    for (int hh = 0; hh < H; ++hh) {
        cin >> S[hh];
    }
    cout << solve(H, W, S) << endl;

    return 0;
}