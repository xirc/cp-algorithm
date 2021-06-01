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

int K, N;
vector<vector<int>> A;

bool can_be_median(int X) {
    int const L = (K * K / 2) + 1;
    vector<vector<int>> M(N+1, vector<int>(N+1, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            M[i+1][j+1] = (A[i][j] > X ? 1 : 0);
        }
    }
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < N; ++j) {
            M[i][j+1] += M[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= N; ++j) {
            M[i+1][j] += M[i][j];
        }
    }
    for (int i = 0; i + K <= N; ++i) {
        for (int j = 0; j + K <= N; ++j) {
            int s = M[i+K][j+K] - M[i][j+K] - M[i+K][j] + M[i][j];
            if (s < L) return true;
        }
    }
    return false;
}

int solve() {
    return binary_search(can_be_median, -1, 1e9);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    cout << solve() << endl;

    return 0;
}