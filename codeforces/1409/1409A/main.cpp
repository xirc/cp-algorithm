#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T, a, b;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> a >> b;
        int dd = abs(a - b);
        int ans = (dd / 10) + (dd % 10 == 0 ? 0 : 1);
        cout << ans << endl;
    }

    return 0;
}