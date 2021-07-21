#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> X;

    cin >> N;
    X.assign(N, 0);
    for (auto &x : X) cin >> x;

    int ans = 1e7;
    for (int c = 1; c <= 100; ++c) {
        int local = 0;
        for (int i = 0; i < N; ++i) {
            int dx = c - X[i];
            local += dx * dx;
        }
        ans = min(ans, local);
    }
    cout << ans << endl;

    return 0;
}