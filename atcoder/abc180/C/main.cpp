#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

set<ll> solve(ll N) {
    set<ll> factors;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            factors.insert(i);
            factors.insert(N / i);
        }
    }
    return factors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;
    cin >> N;
    auto ans = solve(N);
    for (auto v : ans) {
        cout << v << endl;
    }

    return 0;
}