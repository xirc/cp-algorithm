#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H + 2, vector<char>(W + 2, '#'));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cin >> G[y+1][x+1];
        }
    }
    for (int y = 0; y < H + 2; ++y) {
        for (int x = 0; x < W + 2; ++x) {
            cout << G[y][x];
        }
        cout << endl;
    }

    return 0;
}