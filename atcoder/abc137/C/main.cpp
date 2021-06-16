#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<string> S;

ll solve() {
    unordered_map<string, int> mp;
    for (auto& s : S) {
        sort(s.begin(), s.end());
        ++mp[s];
    }
    ll ans = 0;
    for (auto const& s : S) {
        int c = mp[s];
        ans += (c - 1);
    }
    return ans / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    S.assign(N, "");
    for (auto &s : S) cin >> s;
    cout << solve() << endl;

    return 0;
}