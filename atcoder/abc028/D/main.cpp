#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using lf = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    ll M = ll(N) * ll(N) * ll(N);
    ll L = 6 * ll(K-1) * ll(N-K) + 3 * ll(N-K) + 3 * ll(K-1) + 1;
    lf P = lf(L) / lf(M);
    cout << fixed << setprecision(12) << P << endl;

    return 0;
}