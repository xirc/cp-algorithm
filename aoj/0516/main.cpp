#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> A;

int solve() {
    vector<int> DP(N+1, 0);
    for (int i = 0; i < N; ++i) {
        DP[i+1] = DP[i] + A[i];
    }

    int ans = 0;
    for (int i = 0; i + K < N + 1; ++i) {
        int v = DP[i+K] - DP[i];
        ans = max(ans, v);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> N >> K, N != 0 && K != 0) {
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << solve() << endl;
    }

    return 0;
}