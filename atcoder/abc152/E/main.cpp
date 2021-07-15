#include <bits/stdc++.h>

inline int64_t extgcd(
    int64_t const a,
    int64_t const b,
    int64_t &x, int64_t &y
)
{
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int64_t x1, y1;
    int64_t g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

inline int64_t modinv(int64_t a, int64_t m) {
    int64_t x, y, g;
    g = extgcd(a, m, x, y);
    if (g != 1) {
        // There is no modular multiplicative inverse
        return -1;
    }
    return (x % m + m) % m;
}

using namespace std;
using ll = int64_t;
using ff = long double;

int const MOD = 1e9 + 7;

inline map<int,int> prime_factorization(int N) {
    map<int,int> factors;
    for (int i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            factors[i]++;
            N /= i;
        }
    }
    if (N > 1) {
        factors[N]++;
    }
    return factors;
}

inline void lcm(map<int,int>& l, map<int,int> const& b) {
    for (auto e : b) {
        l[e.first] = max(l[e.first], e.second);
    }
}

inline ll toint(map<int,int>& m) {
    ll res = 1;
    for (auto e : m) {
        for (int i = 0; i < e.second; ++i) {
            res *= e.first;
            res %= MOD;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (auto &a : A) cin >> a;

    map<int,int> L;
    vector<map<int,int>> P(N);
    for (int i = 0; i < N; ++i) {
        P[i] = prime_factorization(A[i]);
        lcm(L, P[i]);
    }

    ll LCM = toint(L);
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += LCM * modinv(A[i], MOD);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}