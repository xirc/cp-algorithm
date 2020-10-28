#include <bits/stdc++.h>

using namespace std;

int solve(string const& S) {
    int ans = 1000;
    const int N = S.size();
    for (int i = 0; i + 2 < N; ++i) {
        int M = (S[i] - '0') * 100 + (S[i+1] - '0') * 10 + (S[i+2] - '0');
        ans = min(abs(M - 753), ans);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    cout << solve(S) << endl;

    return 0;
}