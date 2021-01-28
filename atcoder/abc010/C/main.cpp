#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int sx, sy, tx, ty;
int T, V, N;
vector<int> xs, ys;

int pow2(int a) {
    return a * a;
}
bool solve() {
    double EPS = 1e-8;
    int md = pow2(T * V);
    for (int i = 0; i < N; ++i) {
        int x = xs[i], y = ys[i];
        int d1 = pow2(x - sx) + pow2(y - sy);
        int d2 = pow2(x - tx) + pow2(y - ty);
        if (sqrt(d1) + sqrt(d2) < sqrt(md) + EPS) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> sx >> sy >> tx >> ty;
    cin >> T >> V;
    cin >> N;
    xs.assign(N, 0);
    ys.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> xs[i] >> ys[i];
    }
    auto ans = solve() ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}