#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> R;

    cin >> N;
    R.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> R[i];
    }

    sort(R.begin(), R.end());
    reverse(R.begin(), R.end());
    vector<double> S(N, 0);
    for (int i = 0; i < N; ++i) {
        int s = (i & 1) ? -1 : 1;
        S[i] = s * M_PI * R[i] * R[i];
    }
    sort(S.begin(), S.end(), [&](auto l, auto r) {
        return abs(l) < abs(r);
    });
    double ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += S[i];
    }
    cout << fixed << setprecision(7) << ans << endl;

    return 0;
}