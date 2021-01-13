#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int S = A * B, R = C * D;
    if (S > R) {
        cout << S << endl;
    } else {
        cout << R << endl;
    }

    return 0;
}