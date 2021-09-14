#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int L;
    cin >> L;

    ll ans = 1;
    for (int i = 1; i <= 11; ++i) {
        ans *= L- i;
        ans /= i;
    }
    cout << ans << endl;

    return 0;
}