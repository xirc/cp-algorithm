#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(string const& s, int b, int l, ll sum) {
    if (b + l == s.size()) {
        return sum + stoll(s.substr(b, l));
    }
    ll ans = 0;
    ans += solve(s, b + l, 1, sum + stoll(s.substr(b, l)));
    ans += solve(s, b, l + 1, sum);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    cout << solve(s, 0, 1, 0) << endl;

    return 0;
}