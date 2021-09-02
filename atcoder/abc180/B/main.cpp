#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    ll manhattan = 0;
    ff euclid = 0;
    ll chebyshev = 0;
    for (int i = 0; i < N; ++i) {
        ll x;
        cin >> x;
        manhattan += abs(x);
        euclid += x * x;
        chebyshev = max(chebyshev, abs(x));
    }
    euclid = sqrtl(euclid);

    cout << manhattan << endl;
    cout << fixed << setprecision(10) << euclid << endl;
    cout << chebyshev << endl;

    return 0;
}