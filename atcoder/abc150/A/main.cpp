#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K, X;
    cin >> K >> X;
    cout << (500 * K >= X ? "Yes" : "No") << endl;

    return 0;
}