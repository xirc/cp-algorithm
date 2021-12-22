#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, P;
    cin >> N >> P;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        if (a < P) ++ans;
    }
    cout << ans << endl;

    return 0;
}