#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

ll const MOD = 1e9 + 7;
int N, M;
vector<int> xs, ys;

ll solve() {
    ll xx = 0;
    for (int i = 0; i < N; ++i) {
        xx += (ll(i) * xs[i]) - (ll(N - 1 - i) * xs[i]);
        xx %= MOD;
    }
    ll yy = 0;
    for (int i = 0; i < M; ++i) {
        yy += (ll(i) * ys[i]) - (ll(M - 1 - i) * ys[i]);
        yy %= MOD;
    }
    return xx * yy % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    xs.assign(N, 0);
    ys.assign(M, 0);
    for (int i = 0; i < N; ++i) {
        cin >> xs[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> ys[i];
    }
    cout << solve() << endl;

    return 0;
}