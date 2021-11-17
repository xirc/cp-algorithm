#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;
    if (B == 0) {
        cout << "Gold" << endl;
    } else if (A == 0) {
        cout << "Silver" << endl;
    } else {
        cout << "Alloy" << endl;
    }

    return 0;
}