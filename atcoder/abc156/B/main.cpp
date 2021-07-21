#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    int ans = 0;
    while (N > 0) {
        N /= K;
        ++ans;
    }
    cout << ans << endl;

    return 0;
}