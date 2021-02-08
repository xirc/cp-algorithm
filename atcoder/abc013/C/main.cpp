#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

ll N, H;
ll A, B, C, D, E;

ll solve() {
    ll const inf = 1e18;
    ll ans = inf;
    for (ll x = 0; x <= N; ++x) {
        ll K = B * x + D * N - D * x + H - 1;
        if (K < 0) continue;
        ll z = K / (D + E);
        z = min(z, N - x);
        ll y = N - x - z;
        ll cost = A * x + C * y;
        ans = min(ans, cost);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> H;
    cin >> A >> B >> C >> D >> E;
    cout << solve() << endl;

    return 0;
}