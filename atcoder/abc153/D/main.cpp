#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(ll H) {
    assert(H > 0);
    if (H == 1) return 1;
    return 1 + 2 * solve(H / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll H;
    cin >> H;
    cout << solve(H) << endl;

    return 0;
}