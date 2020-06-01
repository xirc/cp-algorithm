#include <bits/stdc++.h>

using namespace std;

using vec2 = complex<double>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    double a, b, c;
    cin >> a >> b >> c;
    c = (c / 180) * M_PI;

    auto va = vec2(a, 0);
    auto vb = vec2(b, 0) * vec2(cos(c), sin(c));
    auto vc = va - vb;

    double h = b * sin(c);
    double L = abs(va) + abs(vb) + abs(vc);
    double S = a * h / 2;

    cout << fixed << setprecision(4);
    cout << S << endl;
    cout << L << endl;
    cout << h << endl;

    return 0;
}