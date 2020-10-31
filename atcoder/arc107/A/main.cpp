#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll M = 998244353;
ll solve(ll A, ll B, ll C) {
    auto Ka = A * (A + 1) / 2;
    auto Kb = B * (B + 1) / 2;
    auto Kc = C * (C + 1) / 2;
    Ka %= M, Kb %= M, Kc %= M;
    auto Kab = (Ka * Kb) % M;
    return (Kab * Kc) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll A, B, C;
    cin >> A >> B >> C;
    cout << solve(A, B, C) << endl;

    return 0;
}