#include <bits/stdc++.h>

using namespace std;

int H, W;
vector<string> A;

vector<vector<char>> solve() {
    vector<bool> eh(H, false), ew(W, false);
    for (int y = 0; y < H; ++y) {
        bool erase_y = true;
        for (int x = 0; x < W; ++x) {
            if (A[y][x] == '#') erase_y = false;
        }
        if (erase_y) {
            eh[y] = true;
        }
    }
    for (int x = 0; x < W; ++x) {
        bool erase_x = true;
        for (int y = 0; y < H; ++y) {
            if (A[y][x] == '#') erase_x = false;
        }
        if (erase_x) {
            ew[x] = true;
        }
    }
    vector<vector<char>> B;
    for (int y = 0; y < H; y++) {
        if (eh[y]) continue;
        B.push_back({});
        for (int x = 0; x < W; ++x) {
            if (ew[x]) continue;
            B.back().push_back(A[y][x]);
        }
    }
    return B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    A.assign(H, "");
    for (int i = 0; i < H; ++i) {
        cin >> A[i];
    }
    auto ans = solve();
    for (int y = 0; y < ans.size(); ++y) {
        for (int x = 0; x < ans[y].size(); ++x) {
            cout << ans[y][x];
        }
        cout << endl;
    }

    return 0;
}