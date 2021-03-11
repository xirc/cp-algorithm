#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, x;
vector<ll> A;

ll solve() {
    ll ops = 0;
    for (int i = 0; i + 1 < N; ++i) {
        ll b = A[i] + A[i+1];
        if (b <= x) continue;
        ll r = min(A[i+1], b - x);
        A[i+1] -= r;
        b -= r;
        ops += r;
        ll q = min(A[i], b - x);
        A[i] -= q;
        b -= q;
        ops += q;
    }
    return ops;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> x;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    cout << solve() << endl;

    return 0;
}