#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

vector<int> solve(int M, int K) {
    if (M == 0) {
        if (K != 0) return {};
        return { 0, 0 };
    }
    if (M == 1) {
        if (K != 0) return {};
        return { 0, 0, 1, 1 };
    }

    int const N = 1 << M;

    if (K >= N) return {};

    vector<int> A(2 * N, 0);
    auto it = A.begin();
    for (int i = 0; i < N; ++i) {
        if (i == K) continue;
        *it = i;
        ++it;
    }
    *it = K;
    ++it;
    for (int i = N - 1; i >= 0; --i) {
        if (i == K) continue;
        *it = i;
        ++it;
    }
    *it = K;
    return A;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int M, K;
    cin >> M >> K;
    auto ans = solve(M, K);
    if (ans.size() == 0) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < ans.size(); ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}