#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<int> H;
vector<int> W;

ll solve() {
    sort(H.begin(), H.end());
    sort(W.begin(), W.end());
    W.erase(unique(W.begin(), W.end()), W.end());

    vector<ll> L(N, 0), R(N, 0);
    for (int i = 1; i < N; i += 2) {
        L[i] = (i-2 > 0) ? L[i-2] : 0;
        L[i] += H[i] - H[i-1];
    }
    for (int i = N - 2; i >= 0; i -= 2) {
        R[i] = (i+2 < N) ? R[i+2] : 0;
        R[i] += H[i+1] - H[i];
    }

    ll ans = numeric_limits<ll>::max();
    for (int i = 0; i < N; i += 2) {
        ll ls = (i-1 >= 0) ? L[i-1] : 0;
        ll rs = (i+1 < N) ? R[i+1] : 0;
        auto lb = lower_bound(W.begin(), W.end(), H[i]);
        if (lb != W.end()) {
            ans = min(ans, ls + rs + (*lb - H[i]));
        }
        auto ub = upper_bound(W.begin(), W.end(), H[i]);
        if (ub != W.begin()) {
            --ub;
            ans = min(ans, ls + rs + (H[i] - *ub));
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    H.assign(N, 0);
    for (auto &h : H) cin >> h;
    W.assign(M, 0);
    for (auto &w : W) cin >> w;
    cout << solve() << endl;

    return 0;
}