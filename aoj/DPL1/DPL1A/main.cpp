#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> C;

int solve() {
    const int inf = numeric_limits<int>::max();
    vector<int> DP(N+1, inf);
    DP[0] = 0;
    for (int c : C) {
        for (int i = 0; i < N+1; ++i) {
            if (DP[i] == inf) continue;
            if (i + c >= N+1) continue;
            DP[i+c] = min(DP[i+c], DP[i]+1);
        }
    }
    return DP[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    C.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> C[i];
    }
    auto ans = solve();
    cout << ans << endl;

    return 0;
}