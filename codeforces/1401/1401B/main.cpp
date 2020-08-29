#include <bits/stdc++.h>

using namespace std;

int solve(int x1, int y1, int z1, int x2, int y2, int z2) {
    // 0,1,2 = x, y, z
    int ans = 0;
    int min_z1y2 = min(z1, y2);
    ans += (min_z1y2) * 2;
    z1 -= min_z1y2;
    y2 -= min_z1y2;
    int min_y1y2 = min(y1, y2);
    y1 -= min_y1y2;
    y2 -= min_y1y2;
    int min_y1x2 = min(y1, x2);
    y1 -= min_y1x2;
    x2 -= min_y1x2;
    int min_y1z2 = min(y1, z2);
    ans -= (min_y1z2) * 2;
    y1 -= min_y1z2;
    z2 -= min_y1z2;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, x1, y1, z1, x2, y2, z2;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        cout << solve(x1, y1, z1, x2, y2, z2) << endl;
    }

    return 0;
}