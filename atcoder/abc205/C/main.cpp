#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

string cmp(int a, int b) {
    if (a > b) {
        return ">";
    } else if (a < b) {
        return "<";
    } else {
        return "=";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    if (C % 2) {
        // odd
        cout << cmp(A, B) << endl;
    } else {
        // even
        cout << cmp(abs(A), abs(B)) << endl;
    }

    return 0;
}