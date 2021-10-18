#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int R, Y, X;
    cin >> R >> X >> Y;

    ll RR = ll(R) * R;
    ll DD = ll(X) * X + ll(Y) * Y;
    int n = 0;
    while (true) {
        if (n * ll(n) * RR >= DD) break;
        ++n;
    }
    if (n == 1 && DD % (n * ll(n) * RR) > 0) {
        ++n;
    }
    cout << n << endl;

    return 0;
}