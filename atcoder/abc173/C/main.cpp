#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, W, K;
    cin >> H >> W >> K;
    vector<string> G(H);
    for (int y = 0; y < H; ++y) {
        cin >> G[y];
        assert(G[y].size() == W);
    }

    int ways = 0;
    for (int s = 0; s < (1 << H); ++s) {
        for (int u = 0; u < (1 << W); ++u) {
            int blacks = 0;
            for (int y = 0; y < H; ++y) {
                if ((s >> y) & 1) continue;
                for (int x = 0; x < W; ++x) {
                    if ((u >> x) & 1) continue;
                    if (G[y][x] == '#') ++blacks;
                }
            }
            if (blacks == K) ++ways;
        }
    }
    cout << ways << endl;

    return 0;
}