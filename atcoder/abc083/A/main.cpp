#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int L = A + B, R = C + D;
    if (L > R) {
        cout << "Left" << endl;
    } else if (L < R) {
        cout << "Right" << endl;
    } else {
        cout << "Balanced" << endl;
    }

    return 0;
}