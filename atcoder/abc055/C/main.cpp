#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll N, ll M) {
    if (N >= M / 2) {
        return M / 2;
    }
    return N + (M - 2 * N) / 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N, M;
    cin >> N >> M;
    cout << solve(N, M) << endl;

    return 0;
}