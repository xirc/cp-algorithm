#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
ll X;
vector<ll> M, B;

ll solve(ll xx, ll nn) {
    if (xx >= M[nn]) return B[nn];
    if (xx == 0) return 0;
    if (nn == 0) return M[0];

    if (xx < M[nn-1] + 2) {
        return solve(xx-1, nn-1);
    } else {
        return B[nn-1] + 1 + solve(xx - 2 - M[nn-1], nn - 1);
    }
}

ll solve() {
    M.assign(N + 1, 0);
    B.assign(N + 1, 0);
    M[0] = 1;
    B[0] = 1;
    for (int i = 1; i < N + 1; ++i) {
        M[i] = 2 * M[i-1] + 3;
        B[i] = 2 * B[i-1] + 1;
    }
    return solve(X, N);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> X;
    cout << solve() << endl;

    return 0;
}