#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    ll const MOD = 1e9 + 7;
    ll ans = 0;
    ll lsum = 0, rsum = 0;
    for (int i = 0; i < K; ++i) {
        lsum += i;
        rsum += (N-i);
    }
    for (int m = K; m <= N+1; ++m) {
        ll c = rsum - lsum + 1;
        ans += c;
        ans %= MOD;
        lsum += m;
        rsum += (N - m);
    }
    cout << ans << endl;

    return 0;
}