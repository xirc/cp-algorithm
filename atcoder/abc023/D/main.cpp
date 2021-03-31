#include <bits/stdc++.h>

inline int64_t binary_search(
    std::function<bool(int64_t)> const& predicate,
    int64_t ng,
    int64_t ok
) {
    assert(!predicate(ng) && predicate(ok));
    while (abs(ok - ng) > 1) {
        auto m = (ok + ng) / 2;
        if (predicate(m)) ok = m;
        else ng = m;
    }
    return ok;
}

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<ll> H, S;

vector<ll> ts;
bool pass(ll const X) {
    for (int i = 0; i < N; ++i) {
        if (X - H[i] < 0) return false;
        ts[i] = (X - H[i]) / S[i];
    }
    sort(ts.begin(), ts.end());
    for (int i = 0; i < N; ++i) {
        if (i > ts[i]) return false;
    }
    return true;
}

ll solve() {
    ts.assign(N, 0);
    ll ng = 0, ok = numeric_limits<ll>::max() / 10;
    return binary_search(pass, ng, ok);
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