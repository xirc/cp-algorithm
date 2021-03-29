#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    vector<int> R;

    cin >> N >> K;
    R.assign(N, 0);
    for (auto &r : R) cin >> r;
    sort(R.begin(), R.end());
    ff rate = 0;
    for (int i = N - K; i < N; ++i) {
        rate = (rate + R[i]) / 2;
    }
    cout << fixed << setprecision(7) << rate << endl;

    return 0;
}