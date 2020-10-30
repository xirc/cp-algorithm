#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> xs, ys, hs;

vector<int> solve() {
    int i;
    for (i = 0; i < N; ++i) {
        if (hs[i] > 0) break;
    }
    swap(xs[i], xs[0]);
    swap(ys[i], ys[0]);
    swap(hs[i], hs[0]);

    for (int cx = 0; cx < 101; ++cx) {
        for (int cy =0; cy < 101; ++cy) {
            const int H = hs[0] + abs(xs[0] - cx) + abs(ys[0] - cy);
            if (H == 0) continue;
            bool pass = true;
            for (int i = 1; i < N; ++i) {
                auto hh = max(H - abs(xs[i] - cx) - abs(ys[i] - cy), 0);
                if (hh != hs[i]) {
                    pass = false;
                    break;
                }
            }
            if (pass) return { cx, cy, H };
        }
    }
    throw;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    xs.assign(N, 0);
    ys = hs = xs;
    for (int i = 0; i < N; ++i) {
        cin >> xs[i] >> ys[i] >> hs[i];
    }
    auto ans = solve();
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;

    return 0;
}