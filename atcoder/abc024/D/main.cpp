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
    int64_t x, y;
    int64_t g;
    g = extgcd(a, m, x, y);
    if (g != 1) {
        // There are no modular multiplicative inverse
        return -1;
    }
    return (x % m + m) % m;
}

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll A, B, C;
    cin >> A >> C >> B;

    ll const MOD = 1e9+7;
    ll cn = (B * C % MOD - A * C % MOD + MOD) % MOD;
    ll rn = (B * C % MOD - A * B % MOD + MOD) % MOD;
    ll d  = (A * B % MOD - B * C % MOD + C * A % MOD + MOD) % MOD;
    ll dd = modinv(d, MOD);
    ll c = cn * dd % MOD;
    ll r = rn * dd % MOD;

    cout << r << " " << c << endl;

    return 0;
}