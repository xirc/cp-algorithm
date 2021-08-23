#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(N);
    vector<int> B(M);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;

    vector<ll> S(M, 0);
    S[0] = B[0];
    for (int i = 1; i < M; ++i) {
        S[i] = S[i-1] + B[i];
    }

    int ans = 0;
    ll Sa = 0;
    for (int i = 0; i <= N; ++i) {
        if (Sa > K) break;
        int b = distance(S.begin(), upper_bound(S.begin(), S.end(), K - Sa));
        ans = max(ans, i + b);
        if (i < N) Sa += A[i];
    }
    cout << ans << endl;

    return 0;
}