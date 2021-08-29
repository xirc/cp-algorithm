#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, W, M;
    cin >> H >> W >> M;

    set<array<int,2>> bombs;
    vector<int> br(H, 0), bc(W, 0);
    for (int i = 0; i < M; ++i) {
        int y, x;
        cin >> y >> x;
        --y, --x;
        bombs.insert({ y, x });
        br[y]++;
        bc[x]++;
    }

    vector<int> bri, bci;
    for (int y = 0; y < H; ++y) {
        if (!bri.empty() && br[bri.back()] > br[y]) continue;
        if (!bri.empty() && br[bri.back()] < br[y]) bri.clear();
        bri.push_back(y);
    }
    for (int x = 0; x < W; ++x) {
        if (!bci.empty() && bc[bci.back()] > bc[x]) continue;
        if (!bci.empty() && bc[bci.back()] < bc[x]) bci.clear();
        bci.push_back(x);
    }

    int ans = 0;
    for (int y : bri) {
        for (int x : bci) {
            int dup = bombs.count({ y, x });
            int nbom = br[y] + bc[x] - dup;
            ans = max(ans, nbom);
            if (dup == 0) break;
        }
    }
    cout << ans << endl;

    return 0;
}