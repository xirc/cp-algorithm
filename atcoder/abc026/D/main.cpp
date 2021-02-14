#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using lf = long double;

int A, B, C;

lf f(lf t) {
    return A * t + B * sin(C * M_PI * t);
}

lf solve() {
    lf l = 0;
    lf r = 200;
    for (int i = 0; i < 400; ++i) {
        lf m = (l + r) / 2.0;
        lf fm = f(m);
        if (abs(fm - 100) < 1e-6) {
            return m;
        } else if (fm - 100 > 0) {
            r = m;
        } else {
            l = m;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A >> B >> C;
    cout << fixed << setprecision(12) << solve() << endl;

    return 0;
}