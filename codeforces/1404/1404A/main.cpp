#include <bits/stdc++.h>

using namespace std;

bool solve(int N, int K, string const& S) {
    vector<bool> ones(K, false);
    vector<bool> zeros(K, false);
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') ones[i%K] = true;
        if (S[i] == '0') zeros[i%K] = true;
    }
    for (int i = 0; i < K; ++i) {
        if (ones[i] && zeros[i]) return false;
    }
    int one_count = 0, zero_count = 0;
    for (int i = 0; i < K; ++i) {
        if (ones[i]) ++one_count;
        if (zeros[i]) ++zero_count;
    }
    if (one_count * 2 > K) return false;
    if (zero_count * 2 > K) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N, K;
    string S;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> K >> S;
        auto ans = solve(N, K, S) ? "YES" : "NO";
        cout << ans << endl;
    }

    return 0;
}