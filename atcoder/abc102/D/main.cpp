#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<ll> A;

ll solve() {
    assert(N >= 4);

    vector<ll> B;
    B.assign(N, 0);
    B[0] = A[0];
    for (int i = 1; i < N; ++i) {
        B[i] = B[i-1] + A[i];
    }

    vector<int> L(N, -1), R(N, -1);

    L[1] = 0;
    for (int i = 2; i < N; ++i) {
        L[i] = L[i-1];
        while (i > L[i]) {
            ll sp0 = B[L[i]];
            ll sq0 = B[i] - B[L[i]];
            ll sp1 = B[L[i]+1];
            ll sq1 = B[i] - B[L[i]+1];
            if (abs(sp1 - sq1) >= abs(sp0 - sq0)) {
                break;
            }
            ++L[i];
        }
    }

    R[N-2] = N-2;
    for (int i = N - 3; i >= 0; --i) {
        R[i] = R[i+1];
        while (R[i] > i) {
            ll sr0 = B[R[i]] - B[i];
            ll ss0 = B[N-1] - B[R[i]];
            ll sr1 = B[R[i]-1] - B[i];
            ll ss1 = B[N-1] - B[R[i]-1];
            if (abs(sr1 - ss1) >= abs(sr0 - ss0)) {
                break;
            }
            --R[i];
        }
    }

    ll ans = numeric_limits<ll>::max();
    for (int i = 1; i + 2 < N; ++i) {
        ll p = B[L[i]];
        ll q = B[i] - B[L[i]];
        ll r = B[R[i]] - B[i];
        ll s = B[N-1] - B[R[i]];
        ans = min(ans, abs(max({ p , q, r, s }) - min({ p, q, r, s })));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}