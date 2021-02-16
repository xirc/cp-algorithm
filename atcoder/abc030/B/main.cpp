#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using lf = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;

    cin >> n >> m;
    n %= 12;

    lf a = m * 360 / lf(60);
    lf b = n * 360 / lf(12) + m * 30 / lf(60);
    lf c = abs(a - b);
    if (c > 180 - 1e-6) {
        c = 360 - c;
    }
    cout << fixed << setprecision(6) << c << endl;

    return 0;
}