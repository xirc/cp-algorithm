#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, W;
    cin >> W >>  a >> b;

    bool isConnected =
      (b >= a && b <= a+W) ||
      (b+W >= a && b+W <= a+W);
    if (isConnected) {
        cout << 0 << endl;
    } else if (a+W <= b) {
        cout << b - (a+W) << endl;
    } else {
        cout << a - (b+W) << endl;
    }

    return 0;
}