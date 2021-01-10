#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(int N) {
    const ll MOD = 1e9+7;
    ll p = 1;
    for (int i = 0; i < N; ++i) {
        p *= (i+1);
        p %= MOD;
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}