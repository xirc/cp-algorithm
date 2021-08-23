#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(N);
    vector<int> B(M);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;

    vector<ll> SA(N+1, 0);
    vector<ll> SB(M+1, 0);
    for (int i = 0; i < N; ++i) {
        SA[i+1] = SA[i] + A[i];
    }
    for (int i = 0; i < M; ++i) {
        SB[i+1] = SB[i] + B[i];
    }

    int ans = 0;
    int j = M;
    for (int i = 0; i <= N; ++i) {
        if (SA[i] > K) break;
        while (SB[j] > K - SA[i])
        {
            --j;
        }
        ans = max(ans, i + j);
    }
    cout << ans << endl;

    return 0;
}