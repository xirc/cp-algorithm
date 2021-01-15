#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, W;
vector<int> wss, vss;

int solve() {
    map<int,int> dp;
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        auto ndp = dp;
        for (auto e : dp) {
            auto w = e.first, v = e.second;
            int nw = w + wss[i];
            int nv = v + vss[i];
            if (nw > W) continue;
            ndp[nw] = max(ndp[nw], nv);
        }
        dp = ndp;
    }

    int ans = 0;
    for (auto e : dp) {
        ans = max(ans, e.second);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> W;
    wss.assign(N, 0);
    vss.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> wss[i] >> vss[i];
    }
    cout << solve() << endl;

    return 0;
}