#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int H, W, N;
vector<array<int,2>> A;

// O(N logN)
vector<ll> solve() {
    map<pair<int,int>,ll> mp;
    for (int i = 0; i < N; ++i) {
        int x = A[i][1], y = A[i][0];
        int lx = max(x-2, 0), ux = min(x, W-3);
        int ly = max(y-2, 0), uy = min(y, H-3);
        for (int cx = lx; cx <= ux; ++cx) {
            for (int cy = ly; cy <= uy; ++cy) {
                auto p = make_pair(cx, cy);
                mp[p] += 1;
            }
        }
    }

    ll blacks = 0;
    vector<ll> ans(10, 0);
    for (auto const& e : mp) {
        assert(e.second > 0);
        ++ans[e.second];
        ++blacks;
    }
    ans[0] = ll(H-2) * ll(W-2) - blacks;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W >> N;
    A.assign(N, { 0, 0 });
    for (int i = 0; i < N; ++i) {
        cin >> A[i][0] >> A[i][1];
        --A[i][0], --A[i][1]; // 0-indexed
    }

    auto ans = solve();
    assert(ans.size() == 10);
    for (auto v : ans) {
        cout << v << endl;
    }

    return 0;
}