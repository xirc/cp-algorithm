#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X, N;
    vector<int> ps;

    cin >> X >> N;
    ps.assign(N, 0);
    for (auto &p : ps) cin >> p;

    set<int> U;
    for (auto p : ps) U.insert(p);

    int ans = 0;
    for (int v = 0; v <= 101; ++v) {
        if (U.count(v)) continue;
        if (abs(X - ans) > abs(X - v)) {
            ans = v;
        }
    }
    cout << ans << endl;

    return 0;
}