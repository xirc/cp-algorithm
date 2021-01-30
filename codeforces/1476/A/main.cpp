#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        int n, k;
        cin >> n >> k;
        if (n % k == 0) {
            cout << 1 << endl;
        } else if (n > k) {
            cout << 2 << endl;
        } else {
            cout << (k + n - 1) / n << endl;
        }
    }

    return 0;
}