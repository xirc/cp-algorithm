#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector<int> A(N), B(N), C(N);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;
    for (auto &c : C) cin >> c;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    vector<ll> DP(N, 0);
    for (int i = 0; i < N; ++i) {
        auto it = lower_bound(A.begin(), A.end(), B[i]);
        int s = distance(A.begin(), it);
        DP[i] = s;
    }
    for (int i = 1; i < N; ++i) {
        DP[i] += DP[i-1];
    }
    ll ans = 0;
    for (auto c : C) {
        auto it = lower_bound(B.begin(), B.end(), c);
        int s = distance(B.begin(), it);
        if (s > 0) {
            ans += DP[s-1];
        }
    }
    cout << ans << endl;

    return 0;
}