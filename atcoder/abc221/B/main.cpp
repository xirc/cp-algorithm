#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

bool solve(string s, string t) {
    if (s.size() != t.size()) return false;
    if (s == t) return true;
    int const n = s.size();
    for (int i = 1; i < n; ++i) {
        swap(s[i], s[i-1]);
        if (s == t) return true;
        swap(s[i], s[i-1]);
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S, T;
    cin >> S >> T;
    auto ans = solve(S, T) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}