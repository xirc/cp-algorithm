#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;
    int C = A + B;
    if (C % 2 == 0) {
        cout << (C / 2) << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}