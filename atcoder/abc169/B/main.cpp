#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<ll> A;

    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;

    int zeros = 0;
    for (auto v : A) {
        if (v == 0) ++zeros;
    }
    if (zeros > 0) {
        cout << 0 << endl;
        return 0;
    }

    ll const U = 1e18;
    ll p = 1;
    for (int i = 0; i < N; ++i) {
        if (A[i] > U / p) {
            p = -1;
            break;
        }
        p *= A[i];
    }
    cout << p << endl;

    return 0;
}