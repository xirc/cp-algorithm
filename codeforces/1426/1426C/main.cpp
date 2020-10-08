#include <bits/stdc++.h>

using namespace std;

inline bool judge(int N, int K) {
    const long long M = (long long)(1 + K / 2) * (1 + K - K / 2);
    return N <= M;
}

int solve(int N) {
    int l = 0, r = 2e9;
    for (int i = 0; i < 100; ++i) {
        int m = (l + r) >> 1;
        if (judge(N, m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        cout << solve(N) << endl;
    }

    return 0;
}