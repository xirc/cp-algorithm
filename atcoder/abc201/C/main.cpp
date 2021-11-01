#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    auto const pass = [&](int a, int b, int c, int d) -> bool {
        for (int n = 0; n < 10; ++n) {
            if (S[n] == 'o') {
                if (a != n && b != n && c != n && d != n) return false;
            } else if (S[n] == 'x') {
                if (a == n || b == n || c == n || d == n) return false;
            }
        }
        return true;
    };

    int ans = 0;
    for (int n = 0; n < 10000; ++n) {
        int m = n;
        int a = m % 10; m /= 10;
        int b = m % 10; m /= 10;
        int c = m % 10; m /= 10;
        int d = m % 10;
        if (pass(a, b, c, d)) {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}