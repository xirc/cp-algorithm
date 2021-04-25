#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int bits(ll N) {
    int bc = 0;
    while (N > 0) {
        N >>= 1;
        ++bc;
    }
    return bc;
}

bool solve(ll N) {
    int const M = bits(N);
    ll v = 1;
    int i = 0;
    for (; v <= N; ++i) {
        v <<= 1;
        if (i % 2 == 0 && M % 2 == 1) {
            v += 1;
        }
        if (i % 2 == 1 && M % 2 == 0) {
            v += 1;
        }
    }
    return i % 2 == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;
    cin >> N;
    auto ans = solve(N) ? "Takahashi" : "Aoki";
    cout << ans << endl;

    return 0;
}