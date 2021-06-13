#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A, B;

    cin >> N;
    A.assign(N + 1, 0);
    B.assign(N, 0);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;

    ll ans = 0;
    for (int i = N - 1; i >= 0; --i) {
        int n = min(A[i+1], B[i]);
        A[i+1] -= n;
        B[i] -= n;
        int m = min(A[i], B[i]);
        A[i] -= m;
        B[i] -= m;
        ans = ans + n + m;
    }
    cout << ans << endl;

    return 0;
}