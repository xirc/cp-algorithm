#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int head(int N) {
    while (N >= 10) {
        N /= 10;
    }
    return N;
}
int tail(int N) {
    return N % 10;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector<vector<ll>> C(10, vector<ll>(10, 0));
    for (int i = 1; i <= N; ++i) {
        int h = head(i), t = tail(i);
        ++C[h][t];
    }

    ll ans = 0;
    for (int h = 1; h <= 9; ++h) {
        for (int t = 1; t <= 9; ++t) {
            ans += ll(C[h][t]) * C[t][h];
        }
    }
    cout << ans << endl;

    return 0;
}