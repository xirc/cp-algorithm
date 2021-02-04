#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    auto p = (A + B == C);
    auto m = (A - B == C);
    if (p && !m) {
        cout << "+" << endl;
    } else if (!p && m) {
        cout << "-" << endl;
    } else if (p && m) {
        cout << "?" << endl;
    } else {
        cout << "!" << endl;
    }

    return 0;
}