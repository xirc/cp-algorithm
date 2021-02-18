#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K, N;
    vector<ll> A;

    cin >> N >> K;
    A.assign(N+1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i+1];
    }
    for (int i = 0; i < N; ++i) {
        A[i+1] += A[i];
    }
    ll ans = 0;
    for (int i = 0; i + K - 1 < N; ++i) {
        ans += A[i+K] - A[i];
    }
    cout << ans << endl;

    return 0;
}