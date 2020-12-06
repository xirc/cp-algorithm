#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, C;
vector<ll> xs;
vector<ll> vs;

ll solve() {
    vector<ll> cw(N, 0), ccw(N, 0);
    cw[0] = vs[0] - xs[0];
    for (int i = 1; i < N; ++i) {
        cw[i] = cw[i-1] + vs[i] - (xs[i] - xs[i-1]);
    }
    ccw[N-1] = vs[N-1] - (C - xs[N-1]);
    for (int i = N - 2; i >= 0; --i) {
        ccw[i] = ccw[i+1] + vs[i] - (xs[i+1] - xs[i]);
    }
    vector<ll> cwb(N, 0), ccwb(N, 0);
    for (int i = 0; i < N; ++i) {
        cwb[i] = cw[i] - xs[i];
        ccwb[i] = ccw[i] - (C - xs[i]);
    }
    vector<ll> mxcw(N, 0), mxccw(N, 0);
    vector<ll> mxcwb(N, 0), mxccwb(N, 0);
    mxcw[0] = cw[0];
    mxcwb[0] = cwb[0];
    for (int i = 1; i < N; ++i) {
        mxcw[i] = max(mxcw[i-1], cw[i]);
        mxcwb[i] = max(mxcwb[i-1], cwb[i]);
    }
    mxccw[N-1] = ccw[N-1];
    mxccwb[N-1] = ccwb[N-1];
    for (int i = N - 2; i >= 0; --i) {
        mxccw[i] = max(mxccw[i+1], ccw[i]);
        mxccwb[i] = max(mxccwb[i+1], ccwb[i]);
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max({ ans, cw[i], ccw[i] });
        if (i + 1 < N) ans = max(ans, mxcwb[i] + mxccw[i+1]);
        if (i > 0) ans = max(ans, mxccwb[i] + mxcw[i-1]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> C;
    xs.assign(N, 0);
    vs.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> xs[i] >> vs[i];
    }
    cout << solve() << endl;

    return 0;
}