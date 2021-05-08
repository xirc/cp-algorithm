#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, W;
vector<int> vs, cs;

// N <= 30
ll solve1() {
    map<ll,ll> mp;
    int const M = N / 2;
    for (int s = 0; s < (1 << M); ++s) {
        ll v = 0, c = 0;
        for (int i = 0; i < M; ++i) {
            if ((s >> i) & 1) {
                v += vs[i];
                c += cs[i];
            }
        }
        mp[c] = max(mp[c], v);
    }

    // accumulate
    {
        ll v = 0;
        for (auto& e : mp) {
            e.second = max(v, e.second);
            v = e.second;
        }
    }

    ll ans = 0;
    int const K = N - M;
    for (int s = 0; s < (1 << K); ++s) {
        ll v = 0, c = 0;
        for (int i = 0; i < K; ++i) {
            if ((s >> i) & 1) {
                v += vs[M + i];
                c += cs[M + i];
            }
        }
        if (c > W) continue;
        auto it = mp.upper_bound(W - c);
        if (it != mp.begin()) {
            --it;
            v += it->second;
        }
        ans = max(ans, v);
    }
    return ans;
}

// all c[i] <= 1000
ll solve2() {
    int const M = 1000 * 200 + 1;
    vector<ll> vmax(M, 0);
    for (int i = 0; i < N; ++i) {
        for (int c = M - 1 - cs[i]; c >= 0; --c) {
            int nc = c + cs[i];
            vmax[nc] = max(vmax[nc], vmax[c] + vs[i]);
        }
    }
    ll ans = 0;
    for (int c = 0; c <= min(W, M-1); ++c) {
        ans = max(ans, vmax[c]);
    }
    return ans;
}

// all vs[i] <= 1000
ll solve3() {
    int const M = 1000 * 200 + 1;
    vector<ll> cmin(M, W + 1);
    cmin[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int v = M - 1 - vs[i]; v >= 0; --v) {
            int nv = v + vs[i];
            cmin[nv] = min(cmin[nv], cmin[v] + cs[i]);
        }
    }
    int ans = 0;
    for (int v = 0; v < M; ++v) {
        if (cmin[v] <= W) {
            ans = max(ans, v);
        }
    }
    return ans;
}

ll solve() {
    if (N <= 30) {
        return solve1();
    }
    if (all_of(cs.begin(), cs.end(), [](auto c) { return c <= 1000; })) {
        return solve2();
    }
    if (all_of(vs.begin(), vs.end(), [](auto v) { return v <= 1000; })) {
        return solve3();
    }
    throw;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> W;
    vs.assign(N, 0);
    cs.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> vs[i] >> cs[i];
    }
    cout << solve() << endl;

    return 0;
}