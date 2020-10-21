#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, W, hh, ww;
    cin >> H >> W >> hh >> ww;

    int ans = (H * W) - (hh * W + ww * H - hh * ww);
    cout << ans << endl;

    return 0;
}