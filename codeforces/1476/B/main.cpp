#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, K;
vector<ll> A;

ll solve() {
    ll ans = 0;
    ll s = A[0];
    for (int i = 1; i < N; ++i) {
        auto m = max(100 * A[i] - s * K, ll(0));
        auto d = (m + K - 1) / K;
        s += A[i] + d;
        ans += d;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> K;
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << solve() << endl;
    }

    return 0;
}