#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    int ans = -1;
    for (int x = A; x <= B; ++x) {
        if (x % C == 0) {
            ans = x;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}