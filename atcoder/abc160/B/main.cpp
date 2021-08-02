#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X;
    cin >> X;

    int S = (X / 500) * 1000;
    int R = (X % 500 / 5) * 5;
    cout << S + R << endl;

    return 0;
}