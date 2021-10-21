#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> X, C;

ll solve() {
    vector<int> cs;
    unordered_map<int, ll> xl, xr;
    for (int i = 0; i < N; ++i) {
        cs.push_back(C[i]);
        if (xl.count(C[i]) == 0) {
            xl[C[i]] = X[i];
        } else {
            xl[C[i]] = min(xl[C[i]], ll(X[i]));
        }
        if (xr.count(C[i]) == 0) {
            xr[C[i]] = X[i];
        } else {
            xr[C[i]] = max(xr[C[i]], ll(X[i]));
        }
    }
    sort(cs.begin(), cs.end());
    cs.erase(unique(cs.begin(), cs.end()), cs.end());

    assert(xl.size() == xr.size());
    int const n = cs.size();
    ll left = abs(xr[cs[0]]) + abs(xr[cs[0]] - xl[cs[0]]);
    ll right = abs(xl[cs[0]]) + abs(xr[cs[0]] - xl[cs[0]]);
    for (int i = 1; i < n; ++i) {
        ll w = abs(xr[cs[i]] - xl[cs[i]]);
        ll next_left = min(
            left + abs(xl[cs[i-1]] - xr[cs[i]]) + w,
            right + abs(xr[cs[i-1]] - xr[cs[i]]) + w
        );
        ll next_right = min(
            left + abs(xl[cs[i-1]] - xl[cs[i]]) + w,
            right + abs(xr[cs[i-1]] - xl[cs[i]]) + w
        );
        left = next_left;
        right = next_right;
    }
    ll ans = min(
        left + abs(xl[cs[n-1]]),
        right + abs(xr[cs[n-1]])
    );
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    X.assign(N, 0);
    C.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> C[i];
    }
    cout << solve() << endl;

    return 0;
}