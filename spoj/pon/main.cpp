// https://www.spoj.com/problems/PON/

#include <iostream>

using namespace std;

using u64 = uint64_t;
using u128 = __int128; // GCC only

u64 pow(u64 base, u64 e, u64 mod) {
    u64 res = 1;
    base %= mod;
    while (e) {
        if (e & 1) {
            res = ((u128)res * base) % mod;
        }
        base = ((u128)base * base) % mod;
        e >>= 1;
    }
    return res;
}

bool satisfy_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = pow(a, d, n);
    if (x == 1 || x == n - 1) {
        return false;
    }
    for (int r = 1; r < s; ++r) {
        x = ((u128)x * x) % n;
        if (x == n - 1) {
            return false;
        }
    }
    return true;
}

// miller rabin algorithm (deterministic in uint64)
bool is_prime(u64 n) {
    if (n < 2) {
        return false;
    }

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    static int bases[] =  { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
    for (int a : bases) {
        if (n == a) {
            return true;
        }
        if (satisfy_composite(n, a, d, r)) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    u64 N;

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N;
        auto ans = is_prime(N) ? "YES" : "NO";
        cout << ans << endl;
    }

    return 0;
}