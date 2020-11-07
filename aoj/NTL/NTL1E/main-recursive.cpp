#include <bits/stdc++.h>

long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extgcd(b, a % b, x1, y1);
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
    extgcd(a, b, x, y);
    cout << x << " " << y << endl;

    return 0;
}