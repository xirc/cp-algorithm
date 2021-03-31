#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X;
    cin >> X;

    int sum = 0;
    while (X > 0) {
        sum += X % 10;
        X /= 10;
    }
    cout << sum << endl;

    return 0;
}