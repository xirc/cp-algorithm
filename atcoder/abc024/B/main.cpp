#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, T;
vector<int> A;

int solve() {
    int const M = 2e6;
    vector<int> DP(M, 0);
    for (int i = 0; i < N; ++i) {
        DP[A[i]] += 1;
        DP[A[i]+T] -= 1;
    }
    int ts = 0;
    for (int i = 1; i < M; ++i) {
        DP[i] += DP[i-1];
    }
    for (int i = 0; i < M; ++i) {
        if (DP[i] > 0) ++ts;
    }
    return ts;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> T;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}