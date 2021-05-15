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

int N, K;
vector<int> A;

bool check(int i) {
    if (i < 0) return false;
    if (i >= N) return true;

    vector<bool> dp(K, false);
    dp[0] = true;
    for (int j = 0; j < N; ++j) {
        if (i == j) continue;
        for (int k = K - 1 - A[j]; k >= 0; --k) {
            dp[k + A[j]] = dp[k + A[j]] || dp[k];
        }
    }

    bool required = false;
    for (int k = K - 1; k >= 0; --k) {
        if (dp[k] && k + A[i] >= K) {
            required = true;
            break;
        }
    }
    return required;
}

int solve() {
    sort(A.begin(), A.end());
    return binary_search(check, -1, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    cout << solve() << endl;

    return 0;
}