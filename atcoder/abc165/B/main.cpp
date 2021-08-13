#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll X;
    cin >> X;

    int y = 0;
    ll c = 100;
    while (c < X) {
         c += c / 100;
         ++y;
    }
    cout << y << endl;

    return 0;
}