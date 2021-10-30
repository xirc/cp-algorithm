#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> count(200, 0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        ++count[A % 200];
    }

    ll ans = 0;
    for (int v = 0; v < 200; ++v) {
        ans += ll(1) * count[v] * max(count[v]-1,0);
    }
    ans /= 2;
    cout << ans << endl;

    return 0;
}