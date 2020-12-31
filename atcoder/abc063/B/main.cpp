#include <bits/stdc++.h>

using namespace std;

bool solve(string const& S) {
    vector<bool> used(26, false);
    for (auto ch : S) {
        int i = ch - 'a';
        if (used[i]) return false;
        used[i] = true;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    auto ans = solve(S) ? "yes" : "no";
    cout << ans << endl;

    return 0;
}