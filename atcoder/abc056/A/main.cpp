#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;

    if (a == "H") {
        cout << b << endl;
    } else {
        cout << (b == "H" ? "D" : "H") << endl;
    }

    return 0;
}