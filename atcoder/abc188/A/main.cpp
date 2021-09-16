#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X, Y;
    cin >> X >> Y;
    bool ans = abs(X - Y) < 3;
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}