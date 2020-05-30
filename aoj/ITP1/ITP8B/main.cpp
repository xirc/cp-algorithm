#include <bits/stdc++.h>

using namespace std;

int solve(const string& s) {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        ans += s[i] - '0';
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    while (cin >> s, s != "0") {
        cout << solve(s) << endl;
    }

    return 0;
}