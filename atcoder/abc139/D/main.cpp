#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    ll ans = ll(N - 1) * ll(N) / 2;
    cout << ans << endl;

    return 0;
}