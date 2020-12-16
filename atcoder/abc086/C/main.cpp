#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> txy;

bool solve() {
    sort(txy.begin(), txy.end());

    int ct = 0, cx = 0, cy = 0;
    for (int i = 0; i < N; ++i) {
        int t = txy[i][0], x = txy[i][1], y = txy[i][2];
        int dt = t - ct;
        int dxy = abs(x - cx) + abs(y - cy);
        if (dxy > dt) return false;
        if ((dt - dxy) % 2 == 1) return false;
        ct = t, cx = x, cy = y;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    txy.assign(N, vector<int>(3));
    for (int i = 0; i < N; ++i) {
        cin >> txy[i][0] >> txy[i][1] >> txy[i][2];
    }
    auto ans = solve() ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}