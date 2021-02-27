#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int ans = n - 1;
    for (int x = 1; x * x <= n; ++x) {
        int y = n / x;
        int mark = (n - x * y) + abs(x - y);
        ans = min(ans, mark);
    }
    cout << ans << endl;

    return 0;
}