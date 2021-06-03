#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X, A;
    cin >> X >> A;
    int B = X < A ? 0 : 10;
    cout << B << endl;

    return 0;
}