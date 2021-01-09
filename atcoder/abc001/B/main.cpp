#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m;
    cin >> m;
    if (m < 100) {
        cout << "00" << endl;
    } else if (m <= 5000) {
        int vv = m / 100;
        cout << setw(2) << setfill('0') << vv << endl;
    } else if (m <= 30000) {
        int vv = m / 1000 + 50;
        cout << vv << endl;
    } else if (m <= 70000) {
        int vv = (m / 1000 - 30) / 5 + 80;
        cout << vv << endl;
    } else {
        cout << 89 << endl;
    }

    return 0;
}