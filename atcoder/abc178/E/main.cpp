#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> xs, ys;

int solve() {
    vector<int> zs(N, 0), ws(N, 0);
    for (int i = 0; i < N; ++i) {
        zs[i] = xs[i] + ys[i];
        ws[i] = xs[i] - ys[i];
    }
    vector<int>::const_iterator zmin, zmax, wmin, wmax;
    tie(zmin, zmax) = minmax_element(zs.begin(), zs.end());
    tie(wmin, wmax) = minmax_element(ws.begin(), ws.end());
    return max(
        *zmax - *zmin,
        *wmax - *wmin
    );
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    xs.assign(N, 0);
    ys.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> xs[i] >> ys[i];
    }
    cout << solve() << endl;

    return 0;
}