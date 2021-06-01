#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    if (a == b) {
        cout << c << endl;
    } else if (b == c) {
        cout << a << endl;
    } else if (c == a) {
        cout << b << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}