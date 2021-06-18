#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(string const& s, string const& t) {
    int const N = s.size();
    vector<int> head(26, -1);
    vector<vector<int>> next(N+1);
    for (int i = N - 1; i >= 0; --i) {
        next[i+1] = head;
        head[s[i]-'a'] = i+1;
    }
    next[0] = head;

    int i = 0;
    int idx = 0;
    ll block = 0;
    while (i < t.size()) {
        auto j = next[idx][t[i]-'a'];
        if (idx == 0 && j == -1) {
            // no ans
            return -1;
        }
        if (j == -1) {
            block += 1;
            idx = 0;
            continue;
        }
        ++i;
        idx = j;
    }
    return block * N + idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s, t;
    cin >> s >> t;
    cout << solve(s, t) << endl;

    return 0;
}