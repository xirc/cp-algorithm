#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int D, T, S;
    cin >> D >> T >> S;

    bool isInTime = D <= T * S;
    cout << (isInTime ? "Yes" : "No") << endl;

    return 0;
}