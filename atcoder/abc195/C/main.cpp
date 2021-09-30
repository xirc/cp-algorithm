#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;
    cin >> N;

    ll ans = 0;
    ll M = 1e15;
    ll C = 5;
    while (M >= 1000) {
        if (N / M >= 1) {
            ans += (N / M - 1) * M * C;
            ans += (N % M) * C + 1;
            N = M;
        }
        M /= 1000;
        C -= 1;
    }
    cout << ans << endl;

    return 0;
}