#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X;
    cin >> X;

    int S = 0;
    for (int i = 1; i <= X; ++i) {
        S += i;
    }
    cout << fixed << setprecision(7) << (ll(S) * 10000 / ff(X)) << endl;

    return 0;
}