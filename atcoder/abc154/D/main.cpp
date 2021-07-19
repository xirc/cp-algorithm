#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    vector<ff> evs;

    cin >> N >> K;
    evs.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        evs[i] = (1 + p) / ff(2);
    }

    ff ev = 0;
    for (int i = 0; i < K; ++i) {
        ev += evs[i];
    }
    ff ans = ev;
    for (int i = K; i < N; ++i) {
        ev -= evs[i-K];
        ev += evs[i];
        ans = max(ans, ev);
    }
    cout << fixed << setprecision(7) << ans << endl;

    return 0;
}