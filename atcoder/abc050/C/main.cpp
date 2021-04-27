#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll const MOD = 1e9 + 7;
int N;
vector<int> A;

ll solve() {
    sort(A.begin(), A.end());
    if (N % 2 == 0 && A[0] == 0) return 0;
    if (N % 2 == 1 && A[0] != 0) return 0;
    for (int i = N % 2; i < N; i += 2) {
        if (i > 0 && A[i] == A[i-1]) return 0;
        if (A[i] != A[i+1]) return 0;
    }
    int M = N / 2;
    ll ans = 1;
    for (int i = 0; i < M; ++i) {
        ans = (ans * 2) % MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    cout << solve() << endl;

    return 0;
}