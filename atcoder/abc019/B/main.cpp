#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;

    char ch = 0;
    int m = 0;
    for (auto c : S) {
        if (ch == 0 || ch == c) {
            ch = c;
            ++m;
        } else {
            cout << ch << m;
            ch = c;
            m = 1;
        }
    }
    if (ch != 0) {
        cout << ch << m;
    }
    cout << endl;

    return 0;
}