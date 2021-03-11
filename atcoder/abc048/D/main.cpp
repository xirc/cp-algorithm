#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

bool solve(string const& s) {
    const int N = s.size();
    auto a = s[0], b = s[s.size()-1];
    if (a == b) {
        return s.size() % 2 == 0;
    } else { // a != b
        return s.size() % 2 == 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    auto ans = solve(s) ? "First" : "Second";
    cout << ans << endl;

    return 0;
}