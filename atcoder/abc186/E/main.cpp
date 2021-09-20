#include <bits/stdc++.h>

inline uint64_t gcd(uint64_t a, uint64_t b) {
    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

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

int64_t modinv(int64_t a, int64_t m) {
    int64_t x, y;
    auto g = extgcd(a, m, x, y);
    if (g != 1) {
        // There is no modular multiplicative inverse
        return -1;
    }
    return (x % m + m) % m;
}

using namespace std;
using ll = int64_t;
using ff = long double;


ll solve(ll N, ll S, ll K) {
    ll g = gcd(N, gcd(S, K));
    N /= g; S /= g; K /= g;
    auto IK = modinv(K, N);
    if (IK == -1) return - 1;
    ll T = (N - S) * IK % N;
    return T;
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    ll N, S, K;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> S >> K;
        cout << solve(N, S, K) << endl;
    }

    return 0;
}