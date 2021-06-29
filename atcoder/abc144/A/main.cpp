#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;

    if (A >= 10 || B >= 10) {
        cout << -1 << endl;
    } else {
        cout << (A * B) << endl;
    }

    return 0;
}