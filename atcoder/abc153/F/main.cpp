#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
ll D, A;
vector<array<ll,2>> XH;

ll solve() {
    sort(XH.begin(), XH.end());

    ll ans = 0;
    vector<ll> Z(N+1, 0);
    for (int i = 0; i < N; ++i) {
        ll x = XH[i][0], h = XH[i][1];
        if (i > 0) Z[i] += Z[i-1];
        if (Z[i] >= h) continue;
        ll c = (h - Z[i] + A - 1) / A;
        array<ll,2> ub = { x + 2 * D, numeric_limits<ll>::max() };
        int j = distance(XH.begin(), upper_bound(XH.begin(), XH.end(), ub));
        Z[i] += c * A;
        Z[j] -= c * A;
        ans += c;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> D >> A;
    XH.assign(N, { 0, 0 });
    for (int i = 0; i < N; ++i) {
        cin >> XH[i][0] >> XH[i][1];
    }
    cout << solve() << endl;

    return 0;
}