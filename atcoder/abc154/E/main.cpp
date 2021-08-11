#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll pow(int n, int k) {
    ll ans = 1;
    for (int i = 0; i < k; ++i) {
        ans *= n;
    }
    return ans;
}

ll perm(int n, int k) {
    ll ans = 1;
    for (int i = 0; i < k; ++i) {
        ans *= n - i;
    }
    return ans;
}

ll comb(int n, int k) {
    if (k > n) return 0;
    return perm(n, k) / perm(k, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    int K;
    cin >> S >> K;

    ll ans = 0;
    int const N = S.size();
    for (int i = 0; i < N; ++i) {
        if (K == 0) continue;
        int D = S[i] - '0';
        if (D == 0) continue;
        int M = N - i - 1;
        ll a0 = comb(M, max(0,K)) * pow(9,K);
        ll ax = max(0,D-1) * comb(M, K-1) * pow(9,K-1);
        ll az = K == 1 ? 1 : 0;
        ans += a0 + ax + az;
        --K;
    }
    cout << ans << endl;

    return 0;
}
