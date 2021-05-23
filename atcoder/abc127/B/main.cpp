#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int r, D, x;
    cin >> r >> D >> x;

    for (int i = 0; i < 10; ++i) {
        x = r * x - D;
        cout << x << endl;
    }

    return 0;
}