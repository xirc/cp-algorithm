#include <bits/stdc++.h>

using namespace std;

int N, T;
vector<int> cs, ts;

int solve() {
    const int inf = 1e5;
    int cost = inf;
    for (int i = 0; i < N; ++i) {
        if (ts[i] > T) continue;
        cost = min(cost, cs[i]);
    }
    return cost == inf ? -1 : cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> T;
    cs.assign(N, 0);
    ts.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> cs[i] >> ts[i];
    }
    auto ans = solve();
    if (ans < 0) {
        cout << "TLE" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}