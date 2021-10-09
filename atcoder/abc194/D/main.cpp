#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    ff ans = 0;
    for (int i = 1; i < N; ++i) {
        ans += ff(N) / i;
    }
    cout << fixed << setprecision(7) << ans << endl;

    return 0;
}