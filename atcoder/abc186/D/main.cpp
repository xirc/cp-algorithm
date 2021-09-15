#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<ll> A;
    
    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;

    sort(A.begin(), A.end());
    ll rhs = 0;
    for (int i = 0; i < N; ++i) {
        rhs += (N - i) * A[i];
    }
    ll lhs = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (i + 1 < N) {
            A[i] += A[i+1];
        }
        lhs += A[i];
    }
    ll ans = lhs - rhs;
    cout << ans << endl;

    return 0;
}