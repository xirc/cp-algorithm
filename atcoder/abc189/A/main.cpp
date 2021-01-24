#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    char a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c) {
        cout << "Won" << endl;
    } else {
        cout << "Lost" << endl;
    }

    return 0;
}