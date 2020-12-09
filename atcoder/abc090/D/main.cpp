#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, K;

ll solve() {
    if (K == 0) {
        return N * N;
    }
    ll ans = 0;
    for (int b = K + 1; b <= N; ++b) {
        ans += (N / b) * (b - K);
        ans += max(ll(0), N % b + 1 - K);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    cout << solve() << endl;

    return 0;
}