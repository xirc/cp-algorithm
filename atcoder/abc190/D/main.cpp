#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

ll solve(ll N) {
    N *= 2;
    ll ans = 0;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i != 0) continue;
        ll j = N / i;
        if ((i + j) % 2 == 0) continue;
        ans += 2;
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