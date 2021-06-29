#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(ll N) {
    ll ans = N;
    for (ll x = 1; x * x <= N; ++x) {
        if (N % x == 0) {
            ll y = N / x;
            ans = min(ans, (x-1)+(y-1));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}