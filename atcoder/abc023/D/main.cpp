#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<ll> H, S;

ll solve() {
    const ll inf = numeric_limits<ll>::max();
    ll ans = 0;
    // O(N**2)
    vector<bool> done(N, false);
    for (int t = N - 1; t >= 0; --t) {
        int min_index;
        ll min_height = inf;
        for (int i = 0; i < N; ++i) {
            if (done[i]) continue;
            ll height = H[i] + t * S[i];
            bool should_update = 
                height < min_height ||
                (height == min_height &&  S[min_index] > S[i]);
            if (should_update) {
                min_height = height;
                min_index = i;
            }
        }
        ans = max(ans, min_height);
        done[min_index] = true;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    H.assign(N, 0);
    S.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> H[i] >> S[i];
    }
    cout << solve() << endl;

    return 0;
}