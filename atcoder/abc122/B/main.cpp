#include <bits/stdc++.h>

using namespace std;

bool match(string const& S) {
    for (int i = 0; i < S.size(); ++i) {
        auto c = S[i];
        if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
            return false;
        }
    }
    return true;
}

int solve(string const& S) {
    const int N = S.size();
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int l = 1; l <= N - i; ++l) {
            if (match(S.substr(i, l))) {
                ans = max(ans, l);
            }
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