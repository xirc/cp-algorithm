#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll X, Y;
    cin >> X >> Y;
    int len = 1;
    while (X * 2 <= Y) {
        ++len;
        X *= 2;
    }
    cout << len << endl;

    return 0;
}