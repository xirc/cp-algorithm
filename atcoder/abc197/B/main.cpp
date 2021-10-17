#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, W, X, Y;
    cin >> H >> W >> Y >> X;
    --X, --Y;

    vector<string> G(H);
    for (auto &s : G) cin >> s;

    int ans = 1;
    for (int ix = X+1; ix < W && G[Y][ix] != '#'; ++ix) ++ans;
    for (int ix = X-1; ix >= 0 && G[Y][ix] != '#'; --ix) ++ans;
    for (int iy = Y+1; iy < H && G[iy][X] != '#'; ++iy) ++ans;
    for (int iy = Y-1; iy >= 0 && G[iy][X] != '#'; --iy) ++ans;
    cout << ans << endl;

    return 0;
}