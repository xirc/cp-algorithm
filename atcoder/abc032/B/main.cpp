#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int solve(string s, int k) {
    if (s.size() < k) {
        return 0;
    }
    set<string> cs;
    for (int i = 0; i + k <= s.size(); ++i) {
        cs.insert(s.substr(i, k));
    }
    return cs.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    int k;

    cin >> s >> k;
    cout << solve(s, k) << endl;

    return 0;
}