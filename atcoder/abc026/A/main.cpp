#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A;
    cin >> A;

    int ans = 0;
    for (int x = 1; x < A; ++x) {
        int y = A - x;
        ans = max(ans, x * y);
    }
    cout << ans << endl;

    return 0;
}