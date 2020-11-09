#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, K;

ll solve() {
    int mod0 = 0, modh = 0;
    for (int i = 1; i <= N; ++i) {
        if (i % K == 0) ++mod0;
        if (K % 2 == 0 && i % K == K/2) ++modh;
    }
    
    ll ans = ll(mod0) * mod0 * mod0;
    if (K % 2 != 0) {
        return ans;
    }
    ans += ll(modh) * modh * modh;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    cout << solve() << endl;

    return 0;
}