#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int K, N;
vector<int> vs;
vector<string> ss;
vector<vector<int>> ds;

vector<int> digits(int v) {
    vector<int> ans;
    while (v > 0) {
        ans.push_back(v % 10);
        v /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<string> try_solve(vector<int>& ls, int i) {
    if (i < ls.size()) {
        for (int c = 1; c <= 3; ++c) {
            ls[i] = c;
            auto ans = try_solve(ls, i+1);
            if (ans.size() > 0) return ans;
        }
        return {};
    }

    vector<string> mp(K, "");
    for (int k = 0; k < N; ++k) {
        auto s = ss[k];
        auto d = ds[k];
        int j = 0;
        for (auto v : d) {
            int len = ls[v-1];
            if (j + len > (int)s.size()) {
                return {};
            }
            auto w = s.substr(j, len);
            j += len;
            if (mp[v-1] == "") {
                mp[v-1] = w;
            } else if (mp[v-1] != w) {
                return {};
            }
        }
        if (j < s.size()) return {};
    }
    return mp;
}

vector<string> solve() {
    for (auto v : vs) ds.push_back(digits(v));
    vector<int> ls(K, 0);
    return try_solve(ls, 0);
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
    assert(ans.size() == K);
    for (int i = 0; i < K; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}