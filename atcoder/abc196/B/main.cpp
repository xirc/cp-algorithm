#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string X;
    cin >> X;
    for (auto c : X) {
        if (c == '.') break;
        cout << c;
    }
    cout << endl;

    return 0;
}