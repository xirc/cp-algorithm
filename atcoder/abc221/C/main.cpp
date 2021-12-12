#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(int n) {
    vector<int> xs;
    while (n > 0) {
        xs.push_back(n % 10);
        n /= 10;
    }

    sort(xs.begin(), xs.end());
    reverse(xs.begin(), xs.end());

    ll ans = 0;
    int const m = xs.size();
    for (int s = 0; s < (1 << m); ++s) {
        int a = 0, b = 0;
        for (int i = 0; i < m; ++i) {
            if (s & (1 << i)) {
                a *= 10;
                a += xs[i];
            } else{
                b *= 10;
                b += xs[i];
            }
        }
        ans = max(ans, ll(a) * b);
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