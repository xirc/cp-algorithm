#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;

    cin >> A >> B;
    for (int C = 0; C < 256; ++C) {
        if ((A ^ C) == B) {
            cout << C << endl;
            break;
        }
    }

    return 0;
}