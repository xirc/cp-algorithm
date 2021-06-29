#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, x;
    cin >> a >> b >> x;
    ff theta;
    if (2 * x >= a * a * b) {
        theta = atan2(2 * a * a * b - 2 * x, a * a * a);
    } else {
        theta = M_PI / ff(2.0) - atan2(2 * x, a * b * b);
    }
    theta = theta * ff(180) / M_PI;
    cout << fixed << setprecision(7) << theta << endl;

    return 0;
}