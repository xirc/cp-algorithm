#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    bool ok = (a + b == c || b + c == a || c + a == b);
    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}