#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(ll N) {
    if (N % 2 == 1) return 0;
    ll ans = 0;
    ll d = 10;
    for (ll d = 10; d <= N; d *= 5) {
        ans += N / d;
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