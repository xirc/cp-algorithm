#include <bits/stdc++.h>

inline uint64_t gcd(uint64_t a, uint64_t b) {
    if (a == 0) return b;
    if (b == 0) return a;

    uint64_t g = 1;
    while (b > 0) {
        if ((a & 1) == 0 && (b & 1) == 0) {
            g <<= 1;
            a >>= 1;
            b >>= 1;
        } else if ((a & 1) == 0) {
            a >>= 1;
        } else if ((b & 1) == 0) {
            b >>= 1;
        } else {
            if (a > b) std::swap(a, b);
            b -= a;
        }
    }
    return g * a;
}


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;

    return 0;
}