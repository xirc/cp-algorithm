#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 26; ++i) {
        int c;
        cin >> c;
        cout << char('a' + c - 1);
    }
    cout << endl;

    return 0;
}