#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if (C * B < A * D) {
        cout << "AOKI" << endl;
    } else if (C * B > A * D) {
        cout << "TAKAHASHI" << endl;
    } else {
        cout << "DRAW" << endl;
    }

    return 0;
}