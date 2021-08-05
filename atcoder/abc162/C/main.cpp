#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int gcd(int a, int b) {
    while (b > 0) {
        int c = a % b;
        a = b, b = c;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K;
    cin >> K;
    ll s = 0;
    for (int a = 1; a <= K; ++a) {
        for (int b = 1; b <= K; ++b) {
            for (int c = 1; c <= K; ++c) {
                s += gcd(a, gcd(b, c));
            }
        }
    }
    cout << s << endl;

    return 0;
}