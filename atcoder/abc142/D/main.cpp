#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll gcd(ll a, ll b) {
    while (b > 0) {
        auto c = a % b;
        a = b;
        b = c;
    }
    return a;
}

set<ll> prime_factorization(ll n) {
    set<ll> ps;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ps.insert(i);
            n /= i;
        }
    }
    if (n > 1) ps.insert(n);
    return ps;
}

int solve(ll A, ll B) {
    ll g = gcd(A, B);
    auto ps = prime_factorization(g);
    return 1 + ps.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll A, B;
    cin >> A >> B;
    cout << solve(A, B) << endl;

    return 0;
}