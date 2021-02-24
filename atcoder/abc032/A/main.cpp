#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int lcm(int a, int b) {
    return a / gcd(a,b) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, n;
    cin >> a >> b >> n;

    int c = lcm(a, b);
    if (c < n) {
        c = c * ((n-1) / c + 1);
    }
    cout << c << endl;

    return 0;
}