#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int const N = 2001;
ll const MOD = 1e9+7;
vector<bool> done(N, false);
vector<int> value(N, 0);
ll solve(int S) {
    if (S < 3) return 0;
    if (done[S]) return value[S];
    ll ans = 1;
    for (int x = 3; x <= S; ++x) {
        int y = S - x;
        ans += solve(y);
        ans %= MOD;
    }
    done[S] = true;
    value[S] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int S;
    cin >> S;
    cout << solve(S) << endl;

    return 0;
}