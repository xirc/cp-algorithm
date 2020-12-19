#include <bits/stdc++.h>

using namespace std;

int N, C;
vector<int> ss, ts, cs;

int solve() {
    const int MXT = 1e5+1;
    const int MXC = 30;
    vector<vector<int>> DP(MXC, vector<int>(MXT, 0));

    for (int i = 0; i < N; ++i) {
        int s = ss[i], t = ts[i], c = cs[i];
        ++DP[c][s-1];
        --DP[c][t];
    }
    for (int c = 0; c < MXC; ++c) {
        for (int t = 1; t < MXT; ++t) {
            DP[c][t] += DP[c][t-1];
        }
    }
    int maxr = 0;
    for (int t = 0; t < MXT; ++t) {
        int r = 0;
        for (int c = 0; c < MXC; ++c) {
            if (DP[c][t] > 0) ++r;
        }
        maxr = max(maxr, r);
    }
    return maxr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> C;
    ss.assign(N, 0);
    ts.assign(N, 0);
    cs.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> ss[i] >> ts[i] >> cs[i];
        --cs[i];
    }
    cout << solve() << endl;

    return 0;
}