#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<ll> A;

ll query(ll K) {
    ll ng = 0, ok = numeric_limits<ll>::max() / 2;
    while (abs(ng - ok) > 1) {
        ll m = (ng + ok) >> 1;
        auto it = upper_bound(A.begin(), A.end(), m);
        ll kk = m - distance(A.begin(), it);
        if (kk >= K) {
            ok = m;
        } else {
            ng = m;
        }
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int Q;
    cin >> N >> Q;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    // A is already sorted.
    for (int i = 0; i < Q; ++i) {
        ll K;
        cin >> K;
        ll ans = query(K);
        cout << ans << endl;
    }

    return 0;
}