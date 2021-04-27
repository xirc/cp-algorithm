#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    vector<int> T;

    cin >> N;
    T.assign(N, 0);
    for (auto &t : T) cin >> t;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int p, x;
        cin >> p >> x;
        --p;

        int ans = 0;
        for (int j = 0; j < N; ++j) {
            if (j == p) ans += x;
            else ans += T[j];
        }
        cout << ans << endl;
    }

    return 0;
}