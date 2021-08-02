#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X, Y, A, B, C;
    vector<int> P, Q, R;
    cin >> X >> Y >> A >> B >> C;
    P.assign(A, 0);
    Q.assign(B, 0);
    R.assign(C, 0);
    for (auto &p : P) cin >> p;
    for (auto &q : Q) cin >> q;
    for (auto &r : R) cin >> r;

    sort(P.begin(), P.end());
    reverse(P.begin(), P.end());
    for (int i = 0; i < X; ++i) R.push_back(P[i]);

    sort(Q.begin(), Q.end());
    reverse(Q.begin(), Q.end());
    for (int i = 0; i < Y; ++i) R.push_back(Q[i]);

    sort(R.begin(), R.end());
    reverse(R.begin(), R.end());
    ll ans = 0;
    for (int i = 0; i < X + Y; ++i) {
        ans += R[i];
    }
    cout << ans << endl;

    return 0;
}