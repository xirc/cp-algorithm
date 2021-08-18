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

    bool zero = false;
    ff pf = 1;
    ll p = 1;
    for (int i = 0; i < N; ++i) {
        pf *= A[i];
        if (A[i] == 0) zero = true;
        if (pf <= 1e18) {
            p *= A[i];
        } else {
            p = -1;
        }
    }
    cout << (zero ? 0 : p) << endl;

    return 0;
}