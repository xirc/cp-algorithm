#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X;
    cin >> X;
    if (X < 40) {
        cout << (40 - X) << endl;
    } else if (X < 70) {
        cout << (70 - X) << endl;
    } else if (X < 90) {
        cout << (90 - X) << endl;
    } else {
        cout << "expert" << endl;
    }

    return 0;
}