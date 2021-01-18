#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int dig(ll N) {
    int r = 0;
    while (N > 0) {
        ++r;
        N /= 10;
    }
    return r;
}

int f(ll a, ll b) {
    return max(dig(a), dig(b));
}

int solve(ll N) {
    int ans = f(1, N);
    for (ll a = 2; a * a <= N; ++a) {
        ll b = N / a;
        if (a * b != N) continue;
        ans = min(ans, f(a, b));
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