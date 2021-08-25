#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll N, K;
vector<ll> A;

ll count_all(ll X) {
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (A[i] - 1) / X;
    }
    return ans;
}

ll solve() {
    ll ng = 0, ok = 1e9;
    while (abs(ok - ng) > 1) {
        ll m = (ng + ok) / 2;
        if (count_all(m) <= K) ok = m;
        else ng = m;
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    cout << solve() << endl;

    return 0;
}