#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int H, W, D;
vector<vector<int>> A;

vector<int> xs, ys;
vector<ll> DP;

void build () {
    xs.assign(H * W, 0);
    ys.assign(H * W, 0);
    DP.assign(H * W, 0);
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            int v = A[y][x];
            xs[v] = x;
            ys[v] = y;
        }
    }
    for (int v = 0; v < H * W; ++v) {
        int x = xs[v], y = ys[v];
        if (v - D < 0) {
            DP[v] = 0;
        } else {
            int u = v - D;
            int px = xs[u], py = ys[u];
            DP[v] = DP[u] + abs(y - py) + abs(x - px);
        }
    }
}

ll query(int L, int R) {
    return DP[R] - DP[L];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> H >> W >> D;
    A.assign(H, vector<int>(W, 0));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cin >> A[y][x];
            --A[y][x];
        }
    }
    build();

    int Q;
    int L, R;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> L >> R;
        --L, --R;
        cout << query(L, R) << endl;
    }

    return 0;
}