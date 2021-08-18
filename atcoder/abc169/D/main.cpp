#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

map<ll,int> prime_factorization(ll const N) {
    ll M = N;
    map<ll, int> factors;
    for (ll p = 2; p * p <= N; ++p) {
        while (M % p == 0) {
            factors[p]++;
            M /= p;
        }
    }
    if (M > 1) factors[M]++;
    return factors;
}

int solve(ll const N) {
    auto factors = prime_factorization(N);
    ll M = N;
    int ans = 0;
    for (auto f : factors) {
        ll p = f.first, e = f.second;
        for (int i = 1; i <= e; ++i) {
            for (int j = 0; j < i; ++j) {
                M /= p;
            }
            e -= i;
            ans++;
        }
        for (int j = 0; j < e; ++j) {
            M /= p;
        }
    }
    assert(M == 1);
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