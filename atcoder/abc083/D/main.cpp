#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(string& S) {
    const int N = S.size();
    int ans = N;
    for (int i = 0; i + 1 < N; ++i) {
        if (S[i] != S[i+1]) {
            int m = max(i+1,N-(i+1));
            ans = min(ans, m);
        }
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