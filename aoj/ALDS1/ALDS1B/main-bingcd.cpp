#include <bits/stdc++.h>

// Binary GCD (a,b)
// Time: O ( log(min(a,b)) )
// The optimized Euclidean algorithm.
// The time complexity is same, but a lot faster than normal one that is using modulo operation.
long long bingcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;

    long long g = 1;
    while (b > 0) {
        if (a & 1 == 0 && b & 1 == 0) {
            g <<= 1;
        } else if (a & 1 == 0) {
            a >>= 1;
        } else if (b & 1 == 0) {
            b >>= 1;
        } else {
            if (a < b) std::swap(a, b);
            a -= b;
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
    cout << bingcd(a, b) << endl;

    return 0;
}