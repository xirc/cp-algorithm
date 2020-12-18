#include <bits/stdc++.h>

using namespace std;

bool solve(string s, string t) {
    const int N = s.size(), M = t.size();
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    return s < t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s, t;
    cin >> s >> t;
    auto ans = solve(s, t) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}