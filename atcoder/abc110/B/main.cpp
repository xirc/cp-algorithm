#include <bits/stdc++.h>

using namespace std;

int N, M, X, Y;
vector<int> xs, ys;

bool solve() {
    auto xmax = *max_element(xs.begin(), xs.end());
    xmax = max(xmax, X);
    auto ymin = *min_element(ys.begin(), ys.end());
    ymin = min(ymin, Y);
    return xmax >= ymin;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> X >> Y;
    xs.assign(N, 0);
    ys.assign(M, 0);
    for (int i = 0; i < N; ++i) {
        cin >> xs[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> ys[i];
    }
    auto ans = solve() ? "War" : "No War";
    cout << ans << endl;

    return 0;
}