#include <bits/stdc++.h>

using namespace std;

bool solve(string const& S) {
    const int N = S.size();
    vector<string> D = { "dream", "dreamer", "erase", "eraser" };
    vector<bool> DP(N, false);
    for (int i = 0; i < N; ++i) {
        if (i != 0 && !DP[i-1]) continue;
        for (auto w : D) {
            if (i + w.size() - 1 >= N) continue;
            bool match = true;
            for (int j = 0; j < w.size(); ++j) {
                if (S[i+j] != w[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                DP[i+w.size()-1] = true;
            }
        }
    }
    return DP[N-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    auto ans = solve(S) ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}