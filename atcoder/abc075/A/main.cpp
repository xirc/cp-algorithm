#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    if (A == B) {
        cout << C << endl;
    } else if (B == C) {
        cout << A << endl;
    } else {
        cout << B << endl;
    }

    return 0;
}