#include <bits/stdc++.h>

// ExtendedGCD(a,b)
// a * x + b * y = gcd(a,b)
// Time: O( log(min(a,b)) )
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    auto g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long a, b, x, y;
    cin >> a >> b;
    extended_gcd(a, b, x, y);
    cout << x << " " << y << endl;

    return 0;
}