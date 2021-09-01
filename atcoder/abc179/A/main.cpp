#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    cout << S;
    if (S.back() == 's') {
        cout << "es";
    } else {
        cout << "s";
    }
    cout << endl;

    return 0;
}