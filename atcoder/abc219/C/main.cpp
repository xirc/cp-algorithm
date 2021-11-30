#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

string X;
int N;
vector<string> S;

void solve() {
    vector<int> t(26, 0);
    for (int i = 0; i < 26; ++i) {
        t[X[i]-'a'] = i;
    }

    sort(S.begin(), S.end(), [&](auto const& l, auto const& r) -> bool {
        int const n = min(l.size(), r.size());
        for (int i = 0; i < n; ++i) {
            auto li = t[l[i]-'a'], ri = t[r[i]-'a'];
            if (li == ri) continue;
            return li < ri;
        }
        return l.size() < r.size();
    });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> X >> N;
    S.assign(N, "");
    for (auto &s: S) {
        cin >> s;
    }

    solve();

    for (auto s : S) {
        cout << s << endl;
    }

    return 0;
}