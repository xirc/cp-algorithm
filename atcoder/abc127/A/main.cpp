#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;

    if (A >= 13) {
        cout << B << endl;
    } else if (A >= 6) {
        cout << (B / 2) << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}