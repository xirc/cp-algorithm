#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(string S) {
    ll const MOD = 1e9 + 7;
    reverse(S.begin(), S.end());
    int e = 1;
    vector<ll> cur(13, 0);
    cur[0] = 1;
    for (auto c : S) {
        vector<ll> next(13, 0);
        for (int d = 0; d < 10; ++d) {
            if (c != '?' && (c - '0') != d) continue;
            int o = d * e % 13;
            for (int i = 0; i < 13; ++i) {
                int j = (i + o) % 13;
                next[j] += cur[i];
                next[j] %= MOD;
            }
        }
        e = e * 10 % 13;
        swap(cur, next);
    }
    return cur[5];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    cout << solve(S) << endl;

    return 0;
}