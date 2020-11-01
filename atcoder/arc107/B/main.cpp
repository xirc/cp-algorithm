#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int f(int N, int K) {
    if (K < 2 || K > 2 *N) {
        return 0;
    }
    return min(K - 1, 2 * N + 1 - K);
}

ll solve(int N, int K) {
    ll ans = 0;
    for (int x = 2; x <= 2 * N; ++x) {
        ans += f(N, x) * (ll)f(N, x - K);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, K;
    cin >> N >> K;
    cout << solve(N, K) << endl;

    return 0;
}