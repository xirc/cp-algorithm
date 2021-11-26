#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> A, B;

ll const MOD = 998244353;

ll solve() {
    vector<array<int,2>> AB;
    for (int i = 0; i < N; ++i) {
        AB.push_back({ A[i], B[i] });
    }
    sort(AB.begin(), AB.end());

    ll ans = 0;
    int const K = 5000;
    vector<ll> DP(K+1, 0);
    DP[0] = 1;
    for (int i = 0; i < N; ++i) {
        auto a = AB[i][0], b = AB[i][1];
        for (int s = K; s - b >= 0; --s) {
            DP[s] += DP[s-b];
            DP[s] %= MOD;
            if (s <= a) {
                ans += DP[s-b];
                ans %= MOD;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    B.assign(N, 0);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;

    cout << solve() << endl;

    return 0;
}