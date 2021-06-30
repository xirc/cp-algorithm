#include <bits/stdc++.h>

inline int64_t binary_search(
    std::function<bool(int64_t)> const& predicate,
    int64_t ng,
    int64_t ok
) {
    assert(!predicate(ng));
    assert(predicate(ok));
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

int N; ll K;
vector<int> A, F;

bool pass(ll M) {
    ll require = 0;
    for (int i = 0; i < N; ++i) {
        if (ll(A[i]) * F[i] <= M) continue;
        ll x = A[i] - M / F[i];
        require += x;
    }
    return require <= K;
}

ll solve() {
    ll acc = accumulate(A.begin(), A.end(), ll(0), plus<ll>());
    if (acc <= K) return 0;

    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    sort(F.begin(), F.end());
    ll ng = 0, ok = 1e13;
    return binary_search(pass, ng, ok);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, 0);
    F.assign(N, 0);
    for (auto &a : A) cin >> a;
    for (auto &f : F) cin >> f;

    cout << solve() << endl;

    return 0;
}