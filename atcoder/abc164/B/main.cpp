#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    while (A > 0 && C > 0) {
        C -= B;
        if (C <= 0) break;
        A -= D;
        if (A <= 0) break;
    }
    cout << (A > 0 ? "Yes" : "No") << endl;

    return 0;
}