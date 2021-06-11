#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A) cin >> a;

    vector<int> l(N, 0), r(N, 0);
    l[0] = A[0];
    r[N-1] = A[N-1];
    for (int i = 1; i < N; ++i) l[i] = max(l[i-1], A[i]);
    for (int i = N-2; i >= 0; --i) r[i] = max(r[i+1], A[i]);

    for (int i = 0; i < N; ++i) {
        int ans = 0;
        if (i > 0) ans = max(ans, l[i-1]);
        if (i < N - 1) ans = max(ans, r[i+1]);
        cout << ans << endl;
    }

    return 0;
}