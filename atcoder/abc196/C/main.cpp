#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int log10(ll n) {
    int m = 0;
    while (n >= 10) {
        n /= 10;
        ++m;
    }
    return m;
}
ll pow10(int m) {
    ll n = 1;
    while (m > 0) {
        n *= 10;
        --m;
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;
    cin >> N;

    int const M = 1e6;
    int ans = 0;
    for (int i = 1; i <= M; ++i) {
        ll n = pow10(log10(i)+1);
        if (i * n + i > N) break;
        ++ans;
    }
    cout << ans << endl;

    return 0;
}