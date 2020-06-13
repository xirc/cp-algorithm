#include <bits/stdc++.h>

using namespace std;

using vector2 = complex<double>;

array<vector2,3> divide_for_koch(const vector2& p1, const vector2& p2) {
    auto v = (p2 - p1) / 3.0;
    auto r = v * vector2(cos(M_PI / 3), sin(M_PI / 3));
    auto s = p1 + v;
    auto t = p2 - v;
    auto u = s + r;
    return { s, u, t };
}

void make_koch_curve(list<vector2>& curve) {
    auto it = curve.begin();
    while (it != curve.end()) {
        auto p1 = *it;
        it++;
        if (it == curve.end()) {
            break;
        }
        auto p2 = *it;
        auto ps = divide_for_koch(p1, p2);
        curve.insert(it, ps.begin(), ps.end());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    list<vector2> curve = { vector2(0, 0), vector2(100, 0) };
    for (int i = 0; i < N; ++i) {
        make_koch_curve(curve);
    }

    cout << fixed << setprecision(4);
    for (auto p : curve) {
        cout << p.real() << " " << p.imag() << endl;
    }

    return 0;
}