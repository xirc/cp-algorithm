#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll x;
    cin >> x;
    ll p = x / 11;
    ll q = x % 11;
    if (q == 0) {
        cout << 2 * p << endl;
    } else if (q <= 6) {
        cout << 2 * p + 1 << endl;
    } else {
        cout << 2 * p + 2 << endl;
    }

    return 0;
}