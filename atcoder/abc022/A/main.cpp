#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using lf = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, S, T;
    int W;

    int ans = 0;
    cin >> N >> S >> T;
    cin >> W;
    for (int i = 0; i < N; ++i) {
        int A = 0;
        if (i > 0) cin >> A;
        W += A;
        if (W >= S && W <= T) ++ans;
    }
    cout << ans << endl;

    return 0;
}