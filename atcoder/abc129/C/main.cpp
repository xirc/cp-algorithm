#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int const MOD = 1e9 + 7;
int N, M;
vector<int> A;

ll solve() {
    set<int> xs;
    for (auto a : A) xs.insert(a);

    vector<ll> DP(N+3, 0);
    DP[0] = 1;
    for (int i = 0; i < N; ++i) {
        if (xs.count(i+1) == 0) {
            DP[i+1] = (DP[i+1] + DP[i]) % MOD;
        }
        if (xs.count(i+2) == 0) {
            DP[i+2] = (DP[i+2] + DP[i]) % MOD;
        }
    }
    return DP[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}