#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> C;

int solve() {
    ll const MOD = 1e9 + 7;

    sort(C.begin(), C.end());

    ll ans = 1;
    for (int i = 0; i < N; ++i) {
        ans *= max(0, C[i] - i);
        ans %= MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    C.assign(N, 0);
    for (auto &c : C) cin >> c;
    cout << solve() << endl;

    return 0;
}