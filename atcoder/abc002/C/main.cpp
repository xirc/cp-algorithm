#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = complex<double>;

double cross(P u, P v) {
    return u.real() * v.imag() - u.imag() * v.real();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, y;
    vector<P> ps(3);
    for (int i = 0; i < 3; ++i) {
        cin >> x >> y;
        ps[i] = P(x, y);
    }

    auto v = ps[0] - ps[1], u = ps[1] - ps[2];
    double s = abs(cross(u, v)) / 2;
    cout << fixed << setprecision(2) << s << endl;

    return 0;
}