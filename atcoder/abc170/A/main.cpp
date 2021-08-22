#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> X(5);
    for (auto &x : X) cin >> x;
    for (int i = 0; i < 5; ++i) {
        if (X[i] == 0) {
            cout << (i + 1) << endl;
            break;
        }
    }

    return 0;
}