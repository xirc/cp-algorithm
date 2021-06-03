#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll W, H, x, y;
    cin >> W >> H >> x >> y;
    ff S = ff(W) * H / 2.0;
    bool has_multiple = x * 2 == W && y * 2 == H;
    cout << fixed << setprecision(10) << S << " " << (has_multiple ? 1 : 0) << endl;

    return 0;
}