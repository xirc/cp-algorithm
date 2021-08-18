#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll A;
    ff B;
    cin >> A >> B;
    ll C = roundl(B * 100);
    cout << (A * C / 100) << endl;

    return 0;
}