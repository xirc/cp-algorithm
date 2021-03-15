#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(ll A, ll B) {
    ll M = (ll)sqrtl(ff(A * B - 1));
    ll ans = 2 * M;
    if (A <= M || B <= M) --ans;
    if (M * (M+1) > A * B - 1) --ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        ll A, B;
        cin >> A >> B;
        cout << solve(A, B) << endl;
    }

    return 0;
}