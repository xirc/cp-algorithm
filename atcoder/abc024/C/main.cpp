#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, D, K;
    vector<int> L, R;
    vector<int> S, T;

    cin >> N >> D >> K;
    L.assign(D, 0);
    R.assign(D, 0);
    for (int i = 0; i < D; ++i) {
        cin >> L[i] >> R[i];
    }
    S.assign(K, 0);
    T.assign(K, 0);
    for (int i = 0; i < K; ++i) {
        cin >> S[i] >> T[i];
    }

    vector<int> arrived_day(K, 0);
    vector<int> xs(K, 0);
    for (int i = 0; i < K; ++i) {
        xs[i] = S[i];
    }
    for (int i = 0; i < D; ++i) {
        auto l = L[i], r = R[i];
        for (int k = 0; k < K; ++k) {
            if (arrived_day[k] > 0) continue;
            if (S[k] < T[k] && l <= xs[k]) {
                xs[k] = max(xs[k], min(r, T[k]));
                if (xs[k] == T[k]) arrived_day[k] = i + 1;
            }
            if (S[k] > T[k] && xs[k] <= r) {
                xs[k] = min(xs[k], max(l, T[k]));
                if (xs[k] == T[k]) arrived_day[k] = i + 1;
            }
        }
    }
    for (int k = 0; k < K; ++k) {
        cout << arrived_day[k] << endl;
    }

    return 0;
}