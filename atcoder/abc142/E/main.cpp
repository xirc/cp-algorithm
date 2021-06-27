#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<int> A;
vector<int> C;

int solve() {
    int const inf = 1e9;
    int const S = 1 << N;
    vector<int> DP(S, inf);
    DP[0] = 0;
    for (int s = 0; s < S; ++s) {
        if (DP[s] == inf) continue;
        for (int i = 0; i < M; ++i) {
            int ns = s | C[i];
            DP[ns] = min(DP[ns], DP[s] + A[i]);
        }
    }
    return (DP[S-1] == inf ? -1 : DP[S-1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(M, 0);
    C.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        int b;
        cin >> A[i] >> b;
        for (int j = 0; j < b; ++j) {
            int c;
            cin >> c;
            --c;
            C[i] |= (1 << c);
        }
    }
    cout << solve() << endl;

    return 0;
}