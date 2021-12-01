#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;

    ll const MOD = 998244353;
    vector<ll> DP(10, 0);
    DP[A[0]] = 1;
    for (int i = 1; i < N; ++i) {
        vector<ll> DPn(10, 0);
        for (int x = 0; x < 10; ++x) {
            int const z1 = (x + A[i]) % 10;
            DPn[z1] += DP[x];
            DPn[z1] %= MOD;
            int const z2 = (x * A[i]) % 10;
            DPn[z2] += DP[x];
            DPn[z2] %= MOD;
        }
        DP = DPn;
    }

    for (int x = 0; x < 10; ++x) {
        cout << DP[x] << endl;
    }

    return 0;
}