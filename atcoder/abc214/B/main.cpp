#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int S, T;
    cin >> S >> T;

    int ans = 0;
    for (int a = 0; a <= S; ++a) {
        for (int b = 0; b <= S - a; ++b) {
            for (int c = 0; c <= S - a - b; ++c) {
                if (a * b * c <= T) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}