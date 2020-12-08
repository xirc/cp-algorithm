#include <bits/stdc++.h>

using namespace std;

int A, B;

const int W = 100;
const int H = 100;
vector<vector<char>> G;

void solve() {
    G = vector<vector<char>>(H, vector<char>(W, ' '));
    for (int x = 0; x < W; ++x) {
        for (int y = 0; y < H / 2; ++y) {
            G[y][x] = '.';
        }
        for (int y = H / 2; y < H; ++y) {
            G[y][x] = '#';
        }
    }
    --A, --B;
    for (int x = 0; x < W; ++x) {
        for (int y = 0; y < H / 2 - 1; y += 2) {
            if (B > 0 && x % 2 == 0) {
                --B;
                G[y][x] = '#';
            }
        }
        for (int y = H - 1; y >= H / 2 + 1; y -= 2) {
            if (A > 0 && x % 2 == 0) {
                --A;
                G[y][x] = '.';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A >> B;
    solve();
    cout << H << " " << W << endl;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cout << G[y][x];
        }
        cout << endl;
    }

    return 0;
}