#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, MA, MB;
vector<int> as, bs, cs;

int solve() {
    map<array<int,2>,int> dp;
    for (int i = 0; i < N; ++i) {
        auto ndp = dp;
        int a = as[i], b = bs[i], c = cs[i];
        if (ndp.count({ a, b })) {
            ndp[{ a, b }] = min(ndp[{ a, b }], c);
        } else {
            ndp[{ a, b }] = c;
        }
        for (auto e : dp) {
            int na = a + e.first[0];
            int nb = b + e.first[1];
            int nc = c + e.second;
            if (ndp.count({ na, nb })) {
                ndp[{ na, nb }] = min(ndp[{ na, nb }], nc);
            } else {
                ndp[{ na, nb }] = nc;
            }
        }
        dp = ndp;
    }
    const int inf = 1e9;
    int ans = inf;
    for (auto e : dp) {
        int a = e.first[0], b = e.first[1], c = e.second;
        if (a * MB == b * MA) {
            ans = min(ans, c);
        }
    }
    return ans == inf ? -1 : ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> MA >> MB;
    as.assign(N, 0);
    bs.assign(N, 0);
    cs.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> as[i] >> bs[i] >> cs[i];
    }
    cout << solve() << endl;

    return 0;
}