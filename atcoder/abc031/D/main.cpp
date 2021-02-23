#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int K, N;
vector<int> vs;
vector<string> ss;

vector<int> digits(int v) {
    vector<int> ans;
    while (v > 0) {
        ans.push_back(v % 10);
        v /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool try_solve(vector<int> const& d, int i, string const& s, int j, vector<string>& mp, set<vector<string>>& ans) {
    if (i == (int)d.size() && j == (int)s.size()) {
        ans.insert(mp);
        return true;
    }
    if (i == (int)d.size()) return false;
    if (j == (int)s.size()) return false;

    if (mp[d[i]] != "") {
        auto w = mp[d[i]];
        if (j + (int)w.size() - 1 >= (int)s.size()) return false;
        for (auto c : w) {
            if (s[j] != c) return false;
            ++j;
        }
        return try_solve(d, i + 1, s, j, mp, ans);
    }

    bool found = false;
    for (int k = 0; k < 3; ++k) {
        if (j + k >= (int)s.size()) continue;
        auto w = s.substr(j, k+1);
        mp[d[i]] = w;
        found |= try_solve(d, i + 1, s, j + k + 1, mp, ans);
        mp[d[i]] = "";
    }
    return found;
}

vector<string> solve() {
    set<vector<string>> cs, ns;
    cs.insert(vector<string>(10, ""));
    for (int i = 0; i < N; ++i) {
        auto d = digits(vs[i]);
        auto s = ss[i];
        ns.clear();
        for (auto mp : cs) {
            try_solve(d, 0, s, 0, mp, ns);
        }
        swap(ns, cs);
    }
    return *cs.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> K >> N;
    vs.assign(N, 0);
    ss.assign(N, "");
    for (int i = 0; i < N; ++i) {
        cin >> vs[i] >> ss[i];
    }
    auto ans = solve();
    for (int i = 0; i < K; ++i) {
        cout << ans[i+1] << endl;
    }

    return 0;
}