#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    if (b - a == c - b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}