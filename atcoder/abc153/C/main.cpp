#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> H(N, 0);
    for (auto &h : H) cin >> h;

    sort(H.begin(), H.end());
    reverse(H.begin(), H.end());
    for (int i = 0; i < min(K, N); ++i) H[i] = 0;

    ll ans = accumulate(H.begin(), H.end(), ll(0), plus<ll>());
    cout << ans << endl;

    return 0;
}