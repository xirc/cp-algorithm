#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
complex<ff> p0, pm;

complex<ff> solve() {
    auto c = (p0 + pm) * ff(0.5);
    auto v = p0 - c;
    auto r = complex<ff>(cos(2 * M_PI / N), sin(2 * M_PI / N));
    auto u = v * r;
    auto p1 = c + u;
    return p1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x0, y0, xm, ym;
    cin >> N;
    cin >> x0 >> y0;
    cin >> xm >> ym;
    p0 = complex<ff>(x0, y0);
    pm = complex<ff>(xm, ym);

    auto p1 = solve();
    cout << fixed << setprecision(6);
    cout << p1.real() << " " << p1.imag() << endl;

    return 0;
}