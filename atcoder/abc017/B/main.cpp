#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

bool solve(string const& S, int i) {
    if (i >= S.size()) return true;
    if (S[i] == 'o' || S[i] == 'k' || S[i] == 'u') {
        return solve(S, i + 1);
    }
    if (S.size() >= 2 && S[i] == 'c' && S[i+1] == 'h') {
        return solve(S, i + 2);
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    auto ans = solve(S, 0) ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}