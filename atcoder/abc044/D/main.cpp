#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll N, S;

ll f(ll b, ll n) {
    if (b <= 1) return 0;
    if (n < b) return n;
    return f(b, n / b) + n % b;
}

ll solve() {
    if (S > N) return -1;
    if (S == N) return N + 1;

    for (ll b = 2; b * b <= N; ++b) {
        if (f(b, N) == S) return b;
    }
    set<ll> bs;
    for (ll p = 1; p * p < N; ++p) {
        ll b = (N - S + p) / p;
        if (f(b, N) == S) {
            bs.insert(b);
        }
    }
    return bs.empty() ? -1 : *bs.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> S;
    cout << solve() << endl;

    return 0;
}