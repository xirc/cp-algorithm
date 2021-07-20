#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
ll K;
vector<ll> A;

ll count(ll X) {
    ll c = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] > 0) {
            ll B = X / A[i];
            auto b = A.begin() + i + 1;
            auto it = upper_bound(b, A.end(), B);
            auto u = distance(b, it);
            c += u;
        } else if (A[i] < 0) {
            auto b = A.begin() + i + 1;
            auto B = X / A[i]; if (X < 0 && X % A[i] != 0) ++B;
            auto it = lower_bound(b, A.end(), B);
            auto l = distance(it, A.end());
            c += l;
        } else { // A[i] == 0
            if (X >= 0) c += N - 1 - i;
        }
    }
    // cout << "count " << X << " " << c << endl;
    return c;
}

ll solve() {
    sort(A.begin(), A.end());

    ll ok = ll(1e18) + 1;
    ll ng = ll(-1e18) - 1;
    assert(count(ok) >= K);
    assert(count(ng) < K);
    while (abs(ok - ng) > 1) {
        ll m = (ok + ng) >> 1;
        if (count(m) >= K) {
            ok = m;
        } else {
            ng = m;
        }
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}