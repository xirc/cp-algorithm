#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll const MOD = 1e9 + 7;
ll pow(int b, int e) {
    ll x = 1;
    for (int i = 0; i < e; ++i) {
        x = x * b % MOD;
    }
    return x;
}

ll solve(int N) {
    if (N <= 1) return 0;
    ll a = pow(10, N);
    ll b = pow(9, N) * 2 % MOD;
    ll c = pow(8, N);
    ll ac = (a + c) % MOD;
    ll abc = (ac - b) % MOD;
    abc = abc < 0 ? (abc + MOD) % MOD : abc;
    return abc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}