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

int N, A, B;
vector<int> H;

bool satisfy(const ll M) {
    int mxh = *max_element(H.begin(), H.end());
    if (mxh / B < M) return true; // prevent an overflow
    assert(B * M <= mxh);

    const int C = A - B;
    assert(C > 0);
    ll mm = M;
    for (auto hi : H) {
        if (hi - B * M <= 0) continue;
        ll mi = (hi - B * M + (C - 1)) / C;
        assert(mi > 0);
        mm -= mi;
        if (mm < 0) return false;
    }
    return true;
}

ll solve() {
    ll ng = 0, ok = 1e15;
    return binary_search(satisfy, ng, ok);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> A >> B;
    H.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    cout << solve() << endl;

    return 0;
}