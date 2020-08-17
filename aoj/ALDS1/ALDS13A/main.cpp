#include <bits/stdc++.h>

using namespace std;

int K;
vector<vector<bool>> G(8, vector<bool>(8, false));

void dump() {
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            cout << (G[r][c] ? "Q" : ".");
        }
        cout << endl;
    }
}

bool can_place(int r, int c) {
    for (int i = -7; i < 8; ++i) {
        if (c+i >= 0 && c+i < 8 && G[r][c+i]) return false;
        if (r+i >= 0 && r+i < 8 && G[r+i][c]) return false;
        if (c+i >= 0 && c+i < 8 && r+i >= 0 && r+i < 8 && G[r+i][c+i]) return false;
        if (c+i >= 0 && c+i < 8 && r-i >= 0 && r-i < 8 && G[r-i][c+i]) return false;
    }
    return true;
}

bool solve(int index, int queens) {
    if (queens == 8) return true;
    for (int i = index; i < 64; ++i) {
        int r = i / 8, c = i % 8;
        if (!can_place(r, c)) continue;
        G[r][c] = true;
        auto ans = solve(8 * (r+1), queens+1);
        if (ans) return true;
        G[r][c] = false;
    }
    return false;
}

void solve() {
    solve(0, K);
    dump();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int r, c;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> r >> c;
        G[r][c] = true;
    }
    solve();

    return 0;
}