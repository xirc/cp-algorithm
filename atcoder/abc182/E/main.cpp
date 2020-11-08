#include <bits/stdc++.h>

using namespace std;

int H, W, N, M;
vector<vector<int>> G;

int solve() {
    bool light = false;
    for (int y = 0; y < H; ++y) {
        light = false;
        for (int x = 0; x < W; ++x) {
            if (G[y][x] < 0)  light = false;
            if (G[y][x] == 1) light = true;
            if (G[y][x] == 0 && light) G[y][x] = 2;
        }
        light = false;
        for (int x = W - 1; x >= 0; --x) {
            if (G[y][x] < 0) light = false;
            if (G[y][x] == 1) light = true;
            if (G[y][x] == 0 && light) G[y][x] = 2;
        }
    }
    for (int x = 0; x < W; ++x) {
        light = false;
        for (int y = 0; y < H; ++y) {
            if (G[y][x] < 0) light = false;
            if (G[y][x] == 1) light = true;
            if (G[y][x] == 0 && light) G[y][x] = 2;
        }
        light = false;
        for (int y = H - 1; y >= 0; --y) {
            if (G[y][x] < 0) light = false;
            if (G[y][x] == 1) light = true;
            if (G[y][x] == 0 && light) G[y][x] = 2;
        }
    }
    int ans = 0;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (G[y][x] > 0) ++ans;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W >> N >> M;
    G.assign(H, vector<int>(W, 0));
    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        G[A][B] = 1;
    }
    for (int i = 0; i < M; ++i) {
        int C, D;
        cin >> C >> D;
        --C, --D;
        G[C][D] = -1;
    }
    cout << solve() << endl;

    return 0;
}