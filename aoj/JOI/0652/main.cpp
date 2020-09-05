#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    int ans = 0;
    while (C > 0) {
        if (A * 7 < C) {
            ans += 7;
            C -= A * 7;
            C -= B;
        } else {
            ans += 1;
            C -= A;
        }
    }
    cout << ans << endl;

    return 0;
}