#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(int const N) {
    ll ans = 0;
    for (int x = 1; x <= N; ++x) {
        int y = N / x;
        ans += ll(1) * y * (y + 1) * x / 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}