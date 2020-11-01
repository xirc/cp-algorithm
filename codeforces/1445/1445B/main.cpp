#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    int a, b, c, d;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> a >> b >> c >> d;
        int ans = max(a + b, c + d);
        cout << ans << endl;
    }

    return 0;
}