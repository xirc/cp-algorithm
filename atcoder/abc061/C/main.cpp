#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
ll K;
vector<int> A, B;

int solve() {
    int const M = 1e5+1;
    vector<ll> DP(M, 0);
    for (int i = 0; i < N; ++i) {
        DP[A[i]] += B[i];
    }
    for (int i = 1; i < M; ++i) {
        DP[i] += DP[i-1];
    }
    auto it = lower_bound(DP.begin(), DP.end(), K);
    return distance(DP.begin(), it);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, 0);
    B.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    cout << solve() << endl;

    return 0;
}