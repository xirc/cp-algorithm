#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;

    int inf = 1200;
    int C;
    for (C = 1; C < inf; ++C) {
        if (C * 8 / 100 != A) continue;
        if (C * 10 / 100 != B) continue;
        break;
    }
    cout << (C != inf ? C : -1) << endl;

    return 0;
}