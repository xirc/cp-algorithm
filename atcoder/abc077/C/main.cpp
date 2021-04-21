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

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        auto ita = lower_bound(A.begin(), A.end(), B[i]);
        int sa = distance(A.begin(), ita);
        auto itb = upper_bound(C.begin(), C.end(), B[i]);
        int sb = distance(itb, C.end());
        ans += ll(sa) * sb;
    }
    cout << ans << endl;

    return 0;
}