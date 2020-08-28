#include <bits/stdc++.h>

using namespace std;

int solve(int N, int K) {
    if (K >= N) return K - N;
    return (N - K) & 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N, K;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> K;
        cout << solve(N, K) << endl;
    }

    return 0;
}