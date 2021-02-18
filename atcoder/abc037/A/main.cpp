#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    int ans = 0;
    int mx = C / A;
    for (int x = 0; x <= mx; ++x) {
        int y = (C - A * x ) / B;
        ans = max(ans, x + y);
    }
    cout << ans << endl;

    return 0;
}