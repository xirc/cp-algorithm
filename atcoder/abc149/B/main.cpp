#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll A, B, K;
    cin >> A >> B >> K;
    ll C = min(A, K);
    A -= C, K -= C;
    ll D = min(B, K);
    B -= D, K -= D;

    cout << A << " " << B << endl;

    return 0;
}