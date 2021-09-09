#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> xs, ys;

bool solve() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            for (int k = 0; k < N; ++k) {
                if (k == i || k == j) continue;
                int lhs = (ys[j] - ys[i]) * (xs[k] - xs[j]);
                int rhs = (ys[k] - ys[j]) * (xs[j] - xs[i]);
                if (lhs == rhs) return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    xs.assign(N, 0);
    ys.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> xs[i] >> ys[i];
    }

    auto ans = solve() ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}