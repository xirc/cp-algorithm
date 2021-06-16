#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K, X;
    cin >> K >> X;
    int b = X - K + 1, e = X + K - 1;
    for (int i = b; i <= e; ++i) {
        if (i > b) cout << " ";
        cout << i;
    }
    cout << endl;

    return 0;
}